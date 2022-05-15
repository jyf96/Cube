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
        if (0 == input.compare("quit"))
        {
            flag = false;
        }
    }
}