#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>

class Point
{
    //  Constructor for creating a `Point` object with specified x and y values
    Point(const double x, const double y) : x{x}, y{y}
    {
    }

    // **Inner factory class:**
    // Encapsulate point creation logic within the `Point` class
    class PointFactory
    {
        // PointFactory constructor
        PointFactory() = default;

      public:
        // PointFactory static method for creating a `Point` object in Cartesian coordinates
        static Point NewCartesian(double x, double y)
        {
            // Creates a `Point` object and returns it
            return {x, y};
        }

        // PointFactory static method for creating a `Point` object in polar coordinates
        static Point NewPolar(double rho, double theta)
        {
            // Convert polar coordinates to Cartesian coordinates
            double x = rho * cos(theta);
            double y = rho * sin(theta);

            // Create a `Point` object with the converted coordinates
            return {x, y};
        }
    };

  public:
    // Public member variables for storing the x and y coordinates
    double x;
    double y;

    // Friend function for custom output formatting of `Point` objects
    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        // Format the output to display the x and y coordinates
        os << "x: " << point.x << " y: " << point.y;
        // Return the output stream for chaining operations
        return os;
    }

    // Declare a static instance of the `PointFactory` class
    static PointFactory Factory;
};

int main()
{
    auto point = Point::Factory.NewCartesian(3, 4);
    std::cout << point << std::endl;

    getchar();
    return 0;
}