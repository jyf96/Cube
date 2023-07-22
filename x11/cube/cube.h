#pragma once
#include "../x11/agent.h"
#define Dimension 3
struct PointShow
{
    int x;
    int y;
    PointShow(int x, int y) : x(x), y(y){};
    PointShow(double x, double y) : x(x), y(y){};
    PointShow() = default;
    ~PointShow() = default;
};
struct Point
{
    double x;
    double y;
    double z;
    Point(double x, double y, double z) : x(x), y(y), z(z){};
    ~Point() = default;
    PointShow ConvertToDimemsion2(Point &view);
};
class Cube
{
public:
    Cube(double size);
    ~Cube(){};
    int Show(MyWindow *myWindow);
    int Move(double move_x, double move_y, double move_z);
    

private:
    /*
        总共三个对象，一个是观察的眼睛，一个是电脑屏幕，还有一个是观察对象
        观察的眼睛就是一个点，观察对象也是一个点，我们需要求出眼睛和观察对象连线和电脑屏幕的交点
        长度单位用像素间距表示，屏幕像素为1920 * 1080    1920像素对应实际长度约300mm
        为方便处理，不妨设电脑屏幕 为 z = 0 (0<=x<1920 0<=y<1080   左上角为原点)
        人眼距离电脑屏幕约40cm 换算成像素点约2400
        则人眼坐标定为 (960,540,2400)
        观察对象坐标原点，暂定放在屏幕左下角，距离屏幕约20cm,则坐标为(0,1080,-1200)，
    */
    Point view;
    Point base;
    double size;
    PointShow pointShows[2][2][2];
    void CreateShowPoint();
};