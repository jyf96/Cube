#include "include/type.h"
#include "include/mythread.h"
#include "x11/agent.h"
#include "usr/usr.h"
#include "cube/cube.h"
using namespace std;
int main()
{
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

    Cube cube(100);

    cube.Show(myWindow);
    
    myWindow->WaitForInternalThreadToExit();
    delete(myWindow);
    return RET_OK;
}