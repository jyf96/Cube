#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/type.h"
#include "agent.h"
int MyWindow::Init()
{
    display = XOpenDisplay(getenv("DISPLAY"));
    if (display == NULL)
    {
        printf("XOpenDisplay failed");
        return RET_ERR;
    }
    printf("%s\n", DisplayString(display));

    XSetWindowAttributes xWindowAttributes = {0};
    unsigned long xWindowAttributesMask = CWBackPixel | CWBorderPixel | CWOverrideRedirect;
    xWindowAttributes.background_pixel = 0xFFFFFF;
    xWindowAttributes.border_pixel = 0x0000FF;
    xWindowAttributes.override_redirect = false;
    window = XCreateWindow(display, XDefaultRootWindow(display),
                           0, 0, width, height, 0, CopyFromParent,
                           InputOutput, CopyFromParent, xWindowAttributesMask, &xWindowAttributes);
    XMapWindow(display, window);
    XSelectInput(display, window, KeyPressMask | ButtonPressMask);
    XGCValues gcValue = {0};
    gcValue.foreground = 0xFFFFFF;
    backgroundGc = XCreateGC(display, window, GCForeground, &gcValue);
    gcValue.foreground = 0x000000;
    foregroundGc = XCreateGC(display, window, GCForeground, &gcValue);
    XSelectInput(display, window, KeyPressMask | ButtonPressMask);

    (void)pthread_mutex_init(&lock,nullptr);
    (void)pthread_cond_init(&cond,nullptr);
    (void)pthread_mutex_init(&eventLock,nullptr);
    return RET_OK;
}
MyWindow::~MyWindow()
{
    if (display != nullptr)
    {
        XDestroyWindow(display, window);
        XCloseDisplay(display);
    }
}
void MyWindow::InternalThreadEntry()
{
    bool flag = true;
    XEvent event;
    while (flag)
    {
        XNextEvent(display, &event);
        pthread_mutex_lock(&lock);
        printf("event.type = %d\n", event.type);
        switch (event.type)
        {
        //键盘
        case KeyPress:
        {
            KeySym keysym;
            char Buff[20] = {0};
            int CharaterNums = 0;
            CharaterNums = XLookupString(&(event.xkey), Buff, 20, &keysym, (XComposeStatus *)nullptr);
            switch(keysym) {
                case XK_q:{
                    printf("press %c,exit!\n", 'q');
                    flag = false;
                    break;
                }
                case XK_Left:
                case XK_Right:
                case XK_Down:
                case XK_Up:{
                    pthread_mutex_lock(&eventLock);
                    if (eventQueue.size() < 10) {
                        eventQueue.push(keysym);
                    }
                    pthread_cond_signal(&cond);
                    pthread_mutex_unlock(&eventLock);
                    break;
                }
                
                default:{
                    printf("keysym is 0x%x\n", keysym);
                }
            }
            if (CharaterNums != 0)
            {
                for (int i = 0; i < CharaterNums; i++)
                {
                    printf("text[%d]=%x %c\n", i, Buff[i], Buff[i]);
                }
            }
            break;
        }
        //鼠标按键
        case ButtonPress:
        {
            printf("ButtonPress :\n");
            unsigned int x = event.xbutton.x;
            unsigned int y = event.xbutton.y;
            int button = event.xbutton.button;
            printf("x = %d,y=%d,button=%d\n", x, y, button);
            switch (button)
            {
            case 1:
            { //鼠标左键
                // XDrawRectangle(display,window,gc,x-10,y-10,20,20);
                // XFillRectangle(display, window, gc, x - 10, y - 10, 20, 20);
                XWindowAttributes attrs;
                XGetWindowAttributes(display, window, &attrs);
                width = attrs.width;
                height = attrs.height;
                printf("width = %d, height = %d\n",width,height);
                break;
            }
            case 3:
            { //鼠标右键
                // XChangeGC(display, gc, GCForeground, &gcValue);
                // XFillRectangle(display, window, gc, 0, 0, width, height);
                break;
            }
            case 4:
            case 5:
            { //鼠标右键
                pthread_mutex_lock(&eventLock);
                if (eventQueue.size() < 10) {
                    eventQueue.push(button);
                }
                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&eventLock);
                break;
            }
            default:
                break;
            }
            break;
        }
        //
        default:
            break;
        }
        pthread_mutex_unlock(&lock);
    }
}
void MyWindow::DrawLine(int x1,int y1,int x2,int y2)
{
    pthread_mutex_lock(&lock);
    printf("x1 = %d,y1 = %d,x2 = %d,y2 = %d\n",x1,y1,x2,y2);
    XDrawLine(display,window,foregroundGc,x1,y1,x2,y2);
    XFlush(display);  /* 显式同步给server */
    pthread_mutex_unlock(&lock);
}
void MyWindow::ClearScreen()
{
    pthread_mutex_lock(&lock);
    XFillRectangle(display,window,backgroundGc,0,0,width,height);
    XFlush(display);  /* 显式同步给server */
    pthread_mutex_unlock(&lock);
}
int MyWindow::GetEvent(int &x,int &y,int &z)
{
    pthread_mutex_lock(&eventLock);
    pthread_cond_wait(&cond,&eventLock);
    if(eventQueue.size() == 0) {
        pthread_mutex_unlock(&eventLock);
        return RET_ERR;
    }
    while(eventQueue.size() > 0) {
        int event = eventQueue.front();
        eventQueue.pop();
        switch(event) {
            case XK_Left: x--; break;
            case XK_Right: x++; break;
            case XK_Down: y++; break;
            case XK_Up: y--; break;
            case 5: z++;break;
            case 4: z--;break;
            default:break;
        }
    }
    pthread_mutex_unlock(&eventLock);
    return RET_OK;
}