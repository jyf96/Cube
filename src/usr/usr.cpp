#include <iostream>
#include "usr.h"
using namespace std;

void MyUsr::InternalThreadEntry()
{
    bool flag = true;
    while (flag)
    {
        string input;
        cin >> input;
        cout << "you put " << input << endl;
        if (0 == input.compare("circle"))
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            printf("you put x1 = %d,y1 = %d,x2 = %d,y2 = %d\n",x1,y1,x2,y2);
            mywindow->DrawCircle(x1, y1, x2, y2);
        }
        else if (0 == input.compare("quit"))
        {
            flag = false;
        }
    }
}