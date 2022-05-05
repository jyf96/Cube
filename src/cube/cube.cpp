#include <iostream>
#include "cube.h"
#include "../include/type.h"

int Point::ConvertToDimemsion2(double &screanX,double &screanY)
{
    /*
        总共三个对象，一个是观察的眼睛，一个是电脑屏幕，还有一个是观察对象
        观察的眼睛就是一个点，观察对象也是一个点，我们需要求出眼睛和观察对象连线和电脑屏幕的交点
        长度单位用像素间距表示，屏幕像素为1920 * 1080    1920像素对应实际长度约300mm
        为方便处理，不妨设电脑屏幕 为 z = 0 (0<=x<1920 0<=y<1080   左上角为原点)
        人眼距离电脑屏幕约40cm 换算成像素点约2400
        则人眼坐标定为 (960,540,2400)
        观察对象坐标原点，暂定放在屏幕左下角，距离屏幕约20cm,则坐标为(0,1080,-1200)，
    */
   const Point view(800,0,1200);
   screanX = (x * view.z - view.x * z) / (view.z-z);
   screanY = (y * view.z - view.y * z) / (view.z-z);
   return RET_OK;
}
Cube::Cube(double size = 100) : size(size)
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++) {
        points[i][j][k] = new Point(0+i*size,500-size*j,-600+k*size);
    }
}
Cube::~Cube()
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++) {
        delete(points[i][j][k]);
    }
}
int Cube::Show(MyWindow *myWindow)
{
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    {
        double x1,y1,x2,y2;
        points[i][j][0]->ConvertToDimemsion2(x1,y1);
        points[i][j][1]->ConvertToDimemsion2(x2,y2);
        myWindow->DrawLine((int)x1,(int)y1,(int)x2,(int)y2);
        points[i][0][j]->ConvertToDimemsion2(x1,y1);
        points[i][1][j]->ConvertToDimemsion2(x2,y2);
        myWindow->DrawLine((int)x1,(int)y1,(int)x2,(int)y2);
        points[0][j][i]->ConvertToDimemsion2(x1,y1);
        points[1][j][i]->ConvertToDimemsion2(x2,y2);
        myWindow->DrawLine((int)x1,(int)y1,(int)x2,(int)y2);
    }
    return RET_OK;
}