#pragma once
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>
#include "../include/mythread.h"

class MyWindow : public MyThreadClass {
    private:
    Display *display = nullptr;
    const int width = 0;
    const int height = 0;
    Window window;
    GC backgroundGc,foregroundGc;
    pthread_mutex_t lock;

    public:
    MyWindow(int _width,int _height): width(_width),height(_height){};
    ~MyWindow();
    int Init();
    void InternalThreadEntry() override;
    void DrawLine(int x1,int y1,int x2,int y2);
};