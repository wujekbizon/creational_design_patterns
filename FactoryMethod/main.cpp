#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>

class Point
{
    // Constructor for creating a `Point` object with specified x and y values
    Point(const double x, const double y) : x{x}, y{y}
    {
    }

    // Public member variables for storing the x and y coordinates
  public:
    double x;
    double y;

    // Factory method for creating a `Point` object in Cartesian coordinates
    static Point NewCartesian(double x, double y)
    {
        // Creates a `Point` object and returns it
        return {x, y};
    }

    // Factory method for creating a `Point` object in polar coordinates
    static Point NewPolar(double rho, double theta)
    {
        // Convert polar coordinates to Cartesian coordinates
        double x = rho * cos(theta);
        double y = rho * sin(theta);

        // Create a `Point` object with the converted coordinates
        return {x, y};
    }

    // Friend function for custom output formatting of `Point` objects
    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        // Format the output to display the x and y coordinates
        os << "x: " << point.x << " y: " << point.y;
        // Return the output stream for chaining operations
        return os;
    }
};

int main()
{
    // Attempt to create a Cartesian point directly using constructor; this will not work
    // Point p{ 1,2 };

    // Instead, use factory methods to create points in specific coordinate systems
    auto point = Point::NewPolar(5, M_PI_4); // Create a polar point with rho=5 and theta=M_PI_4

    // Print the coordinates of the created point
    std::cout << point << std::endl;

    // Wait for input before exiting
    getchar();
    return 0;
}