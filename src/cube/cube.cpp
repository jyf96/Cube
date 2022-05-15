#include <iostream>
#include "cube.h"
#include "../include/type.h"

PointShow Point::ConvertToDimemsion2(Point &view)
{
    double show_x = (x * view.z - view.x * z) / (view.z-z);
    double show_y = (y * view.z - view.y * z) / (view.z-z);
    return PointShow(show_x, show_y);
}
void Cube::CreateShowPoint()
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++)
    {
        pointShows[i][j][k] = Point(base.x+i*size,base.y+j*size,base.z+k*size).ConvertToDimemsion2(view);
    }
}
Cube::Cube(double size = 100) : size(size),
    view(Point(800, 400, 2000)),base(Point(0,0,-size))
{
    CreateShowPoint();
}
int Cube::Show(MyWindow *myWindow)
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    {
        myWindow->DrawLine(pointShows[i][j][0].x,pointShows[i][j][0].y,
            pointShows[i][j][1].x,pointShows[i][j][1].y);
        myWindow->DrawLine(pointShows[i][0][j].x,pointShows[i][0][j].y,
            pointShows[i][1][j].x,pointShows[i][1][j].y);
        myWindow->DrawLine(pointShows[0][i][j].x,pointShows[0][i][j].y,
            pointShows[1][i][j].x,pointShows[1][i][j].y);
    }
    return RET_OK;
}
int Cube::Move(double move_x,double move_y,double move_z)
{
    base.x += move_x;
    base.y += move_y;
    base.z += move_z;
    CreateShowPoint();
    return RET_OK;
}