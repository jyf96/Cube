#pragma once
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>
#include <queue>

enum {
    RET_ERR = -1,
    RET_OK = 0
}E_ERROR;

class MyWindow{
    private:
    Display *display = nullptr;
    const int width = 0;
    const int height = 0;
    Window window;
    GC backgroundGc,foregroundGc;

    public:
    MyWindow(int _width,int _height): width(_width),height(_height){};
    ~MyWindow();
    int Init();
    int Listen()
    int Loop();
};