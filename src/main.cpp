#include "show.h"
#include <pthread.h>
#include <iostream>
#include <string>
using namespace std;
MyWindow *myWindow;
void *MyX11Run(void *)
{
    myWindow = new MyWindow(800,600);
    auto ret = myWindow->Init();
    if(ret != RET_OK) {
        return;
    }
}
void *MyUsrRun(void *)
{
    while (true)
    {
        int i;
        cin >> i;
        cout << "you input " << i << endl;
        if(i==0) {

        }
    }
}
void *MySelfTask(void *)
{
    MyWindow 
}
int main()
{
    pthread_t p_x11;   
    auto ret = pthread_create(&p_x11,nullptr,MyX11Run,nullptr);
    if(ret != RET_OK) {
        return ret;
    }

    pthread_t p_usr;   
    auto ret = pthread_create(&p_usr,nullptr,MyX11Run,nullptr);
    if(ret != RET_OK) {
        return ret;
    }
    pthread_t p_selftask;   
    auto ret = pthread_create(&p_selftask,nullptr,MyX11Run,nullptr);
    if(ret != RET_OK) {
        return ret;
    }

    return RET_OK;
    
    return 0;
}