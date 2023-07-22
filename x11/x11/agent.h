#pragma once
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>
#include "../include/mythread.h"
#include <queue>

class MyWindow : public MyThreadClass {
    private:
    Display *display = nullptr;
    int width = 0;
    int height = 0;
    Window window;
    GC backgroundGc,foregroundGc;
    pthread_mutex_t lock;
    pthread_mutex_t eventLock;
    pthread_cond_t cond;
    std::queue<int> eventQueue;

    public:
    MyWindow(int _width,int _height): 
        width(_width),height(_height){};
    ~MyWindow();
    int Init();
    void InternalThreadEntry() override;
    void DrawLine(int x1,int y1,int x2,int y2);
    void ClearScreen();
    int GetEvent(int &x,int &y,int &z);
};