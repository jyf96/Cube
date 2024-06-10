#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader_s.hpp>
#include <texture_2d_s.hpp>
#include <camera.hpp>

#include <iostream>
#include <map>
/* opengl坐标系 */
struct Coordinate{
    float x;
    float y;
    float z;
    Coordinate(float x, float y, float z):x(x),y(y),z(z){};
};

struct TextTure{
    float x;
    float y;
    TextTure(float x, float y):x(x),y(y){};
};

struct Point{
    Coordinate coordinate;
    TextTure textTure;
    Point(Coordinate coordinate, TextTure textTure):coordinate(coordinate),textTure(textTure){};
};

class Triangle
{
public:
    std::vector<Point> points;
    void *p;
    Triangle(void):p(nullptr)
    {
        points.push_back( Point( Coordinate(-0.5,0,0), TextTure(0,0)));
        points.push_back( Point( Coordinate(0,0.5,0), TextTure(0.5,1)));
        points.push_back( Point( Coordinate(0,0.5,0), TextTure(1,0)));
    }
    void *GetPoints(void)
    {
        if (!p) {
            p = malloc(sizeof(Point) * points.size());
        }
        int i = 0;
        for(auto point : points) {
            memcpy((Point *)&p[i], &point, sizeof(Point));
        }
    }
};