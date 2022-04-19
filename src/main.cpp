#include "show.h"
#include <pthread.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef enum{
    EVENT_TYPE_OF_SHOW,
    EVENT_TYPE_OF_USR
}EVENT_TYPE;
struct Event{
    EVENT_TYPE type;
    union{
        XEvent xEvent;
    }data;
};
void *MyUsrRun(void *)
{
    while (true)
    {
        string s;
        cin >> s;
        cout << "you input " << s << endl;
    }
}
int main()
{
    queue<Event> eventQueue;
    pthread_t p_usr;
    int ret;
    ret = pthread_create(&p_usr,nullptr,MyUsrRun,nullptr);
    if(ret != RET_OK) {
        return ret;
    }
    MyWindow myWindow = MyWindow(800,600);
    ret = myWindow.Init();
    if(ret != RET_OK) {
        return ret;
    }
    while(true) {

    }
    return RET_OK;
}