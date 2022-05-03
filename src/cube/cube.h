#pragma once

#include <Eigen/Core>
#include <Eigen/LU>

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
int cube_test();