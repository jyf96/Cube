#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <X11/Xlib.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>


int show_test()
{
    /* Xlib */
    Display *display = XOpenDisplay(getenv("DISPLAY"));
    if (display == NULL)
    {
        perror("XOpenDisplay failed");
        return -1;
    }
    printf("%s\n", DisplayString(display));

    const int width = 1920;
    const int height = 1080;

    XSetWindowAttributes xWindowAttributes = {0};
    unsigned long xWindowAttributesMask = CWBackPixel | CWBorderPixel | CWOverrideRedirect;
    xWindowAttributes.background_pixel = 0xFFFFFF;
    xWindowAttributes.border_pixel = 0x0000FF;
    xWindowAttributes.override_redirect = false;
    
    Window window = XCreateWindow(display, XDefaultRootWindow(display),
                                  0, 0, width, height, 0, CopyFromParent,
                                  InputOutput, CopyFromParent, xWindowAttributesMask, &xWindowAttributes);
    XMapWindow(display, window);
    XGCValues gcValue = {0};
    gcValue.foreground = 0xFFFF00;
    GC gc = XCreateGC(display, window, GCForeground, &gcValue);
    XFillRectangle(display, window, gc, width-100, height-50,100,50);
    // Pixmap pixmap = XCreatePixmap(display,window,width, height, 24);

    XSelectInput(display, window, KeyPressMask | ButtonPressMask | ExposureMask | FocusChangeMask);

    XEvent event;
    while (True)
    {
        XNextEvent(display, &event);
        printf("event.type = %d\n",event.type);
        switch (event.type)
        {
            
        case KeyPress:
        {
            KeySym keysym;
            char Buff[20] = {0};
            int CharaterNums = 0;
            CharaterNums = XLookupString(&(event.xkey), Buff, 20, &keysym, (XComposeStatus *)nullptr);
            if (CharaterNums != 0)
            {
                for (int i = 0; i < CharaterNums; i++)
                {
                    printf("text[%d]=%x %c\n", i, Buff[i], Buff[i]);
                }

                if (keysym == XK_q)
                {
                    printf("press %c,exit!\n", 'q');
                    XCloseDisplay(display);
                    return 0;
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
                case 1: {  //鼠标左键
                    XGCValues gcValue = {0};
                    int i,j;
                    for(i=0;i<width && i< 256;i++) {
                        for(j=0;j<width && j < 256;j++) {
                            gcValue.foreground = (i & 0xff) + ((j &0xff) << 8);
                            XChangeGC(display, gc, GCForeground, &gcValue);
                            XDrawPoint(display,window,gc,i,j);
                        }
                    }
                    // XDrawRectangle(display,window,gc,x-10,y-10,20,20);
                    //XFillRectangle(display, window, gc, x - 10, y - 10, 20, 20);
                    break;
                }
                case 3: {  //鼠标右键
                    XGCValues gcValue = {0};
                    gcValue.foreground = 0xFFFFFF;
                    XChangeGC(display, gc, GCForeground, &gcValue);
                    XFillRectangle(display, window, gc, 0, 0, width, height);
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case Expose:
        {
            break;
        }

        default:
            break;
        }
    }
    return 0;
}