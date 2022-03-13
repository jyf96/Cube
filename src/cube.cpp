#include <Eigen/Core>
#include <Eigen/LU>
#include <iostream>
using namespace Eigen;
using namespace std;

#define Dimension 3
typedef Matrix<double,1,Dimension> Point;
typedef Matrix<double,1,Dimension> Vector;
struct Line{
    Point start;
    Point end;
};
struct plane{
    Point pointList[3];
};
class Cube {
    Point apex[2][2][2];
};
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