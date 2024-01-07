#include <cmath>
#include <iostream>

enum class PointType
{
    cartesian,
    polar
};

struct Point
{
    // Point(float x, float y) : x(x), y(y){}

    //!
    //! \param a this is either x or rho
    //! \param b this is either y or theta
    //! \param type
    Point(float a, float b, PointType type = PointType::cartesian)
    {
        if (type == PointType::cartesian)
        {
            x = a;
            y = b;
        }
        else
        {
            x = a * cos(b);
            y = a * sin(b);
        }
    }

    float x;
    float y;
};

int main()
{

    return 0;
}