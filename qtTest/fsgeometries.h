#ifndef FSGEOMETRIES_H
#define FSGEOMETRIES_H

//typedef double double; //in cm
typedef unsigned char FSUChar; //in cm
typedef unsigned char FSBool;

/********************************/
/*          FS_COLOR            */
/********************************/

typedef struct _FSColor
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} FSColor;

static FSColor FSMakeColor(FSUChar red, FSUChar green, FSUChar blue)
{
    FSColor c;
    c.red = red;
    c.green = green;
    c.blue = blue;
    return c;
}

/********************************/
/*          FS_POINT            */
/********************************/

typedef struct FSPoint//_FSPoint
{
  double x;
  double y;
  double z;
  FSColor color;
} ;



static FSPoint FSMakePoint(double x, double y, double z)
{
    FSPoint p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

/********************************/
/*          FS_SIZE            */
/********************************/

typedef struct _FSSize
{
  double width;
  double height;
  double depth;
} FSSize;

static FSSize FSMakeSize(double width, double height, double depth)
{
    FSSize s;
    s.width = width;
    s.height = height;
    s.depth = depth;
    return s;
}

/********************************/
/*          FS_LINE             */
/********************************/

typedef struct _FSLine
{
  double a;
  double b;
} FSLine;

static FSLine FSMakeLine(double a, double b)
{
    FSLine l;
    l.a = a;
    l.b = b;
    return l;
}

/********************************/
/*          FS_MISC             */
/********************************/

typedef enum
{
  FS_DIRECTION_CCW,
  FS_DIRECTION_CW
} FSDirection;

//points must have same height
static FSLine computeLineFromPoints(FSPoint p1, FSPoint p2)
{
  FSLine l;
  l.a = (p2.z-p1.z)/(p2.x-p1.x);
  l.b = p1.z-l.a*p1.x;
  return l;
}

//lines must be on same plane
static FSPoint computeIntersectionOfLines(FSLine l1, FSLine l2)
{
  FSPoint i; //intersection of the two coplanar lines
  i.x = (l2.b-l1.b)/(l1.a-l2.a);
  i.z = l2.a*i.x+l2.b;
  return i;
}

#endif // FSGEOMETRIES_H
