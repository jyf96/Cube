#pragma once
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>
#include "../include/mythread.h"

enum {
    RET_ERR = -1,
    RET_OK = 0
}E_ERROR;

class MyWindow : public MyThreadClass {
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
    void InternalThreadEntry() override;
};