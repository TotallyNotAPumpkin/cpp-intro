#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"
#include "AUV.hpp"
#include <math.h>
#include <vector>
#include <string>
#include <array>

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  return x / y;
}

class Circle {
  public:
  double radius;
  Circle(double r) {
    this->radius = r;
  }

  double area() {
    return M_PI * pow(radius, 2);
  }
};

int main()
{
  std::cout << "Emily Wang 115" << std::endl;

  int x = 8;
  int y = 4;
  int z = 3;
  int w = 4;
  int v = 1;
  std::cout << "The sum of " << x << " and " << y << " is " << add(x, y) << std::endl;
  std::cout << "The sum of " << x << ", " << y << ", and " << z << " is " << add(x, add(y, z)) << std::endl;
  std::cout << "The product of " << x << ", " << y << ", " << w << ", and " << z << " is " << multiply(multiply(y, w), z) << std::endl;
  std::cout << "The quotient of " << x << ", " << y << ", and " << v << " is " << divide(divide(x, y), v) << std::endl;

  Circle c = Circle(1);
  std::cout << "The area of the circle is: " << c.area() << std::endl;

  Point p = Point(5, 5);
  Point p1 = Point(2, 2);
  Point p3 = Point(3, 1);
  Line l = Line(p, p1);
  Triangle t = Triangle(p, p1, p3);
  Polygon b = Polygon({p, p1, p3});

  std::cout << "The distance from point (" << p.x() << ", " << p.y() << ") and the origin is " << p.distance_to_origin() << std::endl; 
  std::cout << "The distance from point (" << p.x() << ", " << p.y() << ") and point (" << p1.x() << ", " << p1.y() << ") is " << p.distance_to_point(p1) << std::endl;
  std::cout << "The length from of line p-p1 is " << l.length() << std::endl;
  std::cout << "The distance from point p to line l is: " << l.distance_to_point(p3) << std::endl;
  std::cout << "The area of triangle p1, p2, p3 is: " << t.area() << std::endl;
  std::cout << "The area of polygon b is: " << b.area() << std::endl;
  std::cout << "The perimeter of polygon b is: " << b.perimeter() << std::endl;
  return 0;
}