#include "include/mythread.h"
#include "x11/agent.h"
using namespace std;
int main()
{
    MyWindow *myWindow = new MyWindow(800,600);
    auto ret = myWindow->Init();
    if(ret != RET_OK) {
        return ret;
    }
    myWindow->StartInternalThread();
    myWindow->WaitForInternalThreadToExit();
    delete(myWindow);
    return RET_OK;
}