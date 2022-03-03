#include<stdio.h>
struct Point3{
    int x,y,z;
};
struct Line{
    Point3 start;
    Point3 end;
}
class Cube {
    Point3 apex[2][2][2];
    Point3 Viewer;
};