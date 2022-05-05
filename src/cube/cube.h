#pragma once
#include "../x11/agent.h"
#define Dimension 3
class Point{
    public:
    double x;
    double y;
    double z;
    Point(double x,double y,double z) : x(x),y(y),z(z){};
    ~Point() = default;
    int ConvertToDimemsion2(double &screanX,double &screanY);
};
class  Cube{
    public:
    double size;
    Point *points[2][2][2];
    Cube(double size);
    ~Cube();
    int Show(MyWindow *myWindow);
};