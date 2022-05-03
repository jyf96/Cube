#pragma once
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>
#include "../include/mythread.h"
#include "../x11/agent.h"

class MyUsr : public MyThreadClass {
    private:
        MyWindow *mywindow = nullptr;
    public:
    MyUsr(MyWindow *mywindow) : mywindow(mywindow) {};
    void InternalThreadEntry() override;
};