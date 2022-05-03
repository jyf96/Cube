#include <iostream>
#include "cube.h"

int cube_test()
{
    Matrix<double,2,2> a;
    a << 2,-1,
        -1, 2;
    cout << a << endl;
    Matrix<double,1,2> b;
    b << 0,3;
    cout << b << endl;
    cout << a.inverse() << endl;
    cout << a.inverse()*b.transpose() << endl;
    Matrix<double,3,2> c;
    c << a,
         b;
    cout << c << endl;
    return 0;
}