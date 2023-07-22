#include "include/type.h"
#include "include/mythread.h"
#include "x11/agent.h"
#include "usr/usr.h"
#include "cube/cube.h"
#include <queue>
#include <unistd.h>
using namespace std;
int main()
{
    queue<int> eventQueue;
    MyWindow *myWindow = new MyWindow(800,600);
    auto ret = myWindow->Init();
    if(ret != RET_OK) {
        return ret;
    }
    myWindow->StartInternalThread();
    // MyUsr *usr = new MyUsr(myWindow);
    // usr->StartInternalThread();
    // usr->WaitForInternalThreadToExit();
    // delete(usr);

    Cube cube(200);
    cube.Show(myWindow);
    while(true)
    {
        int x = 0,y = 0,z=0;
        if(myWindow->GetEvent(x,y,z) == RET_OK) {
            cube.Move(x*100,y*100,z*100);
            myWindow->ClearScreen();
            cube.Show(myWindow);
        }  
    }
    
    myWindow->WaitForInternalThreadToExit();
    delete(myWindow);
    return RET_OK;
}