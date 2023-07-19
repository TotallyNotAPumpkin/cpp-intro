#include <iostream>
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

// problem 1 and 2
class Point {
  public:
  double x;
  double y;

  Point(double m, double n) {
    this->x = m;
    this->y = n;
  }

  double distance_to_origin() {
    return sqrt(pow(x, 2) + pow(y, 2)); 
  }

  double distance_to_point(Point a) {
    return sqrt(pow((a.y-y), 2) + pow((a.x-x), 2));
  }
};

// problem 3 and 4
class Line {
  public:
  Point p1;
  Point p2;

  Line(const Point &p1, const Point &p2): p1(p1), p2(p2) {
  }

  double length() {
    return sqrt(pow((p1.y-p2.y), 2) + pow((p1.x-p2.x), 2));
  }

  double distance_to_point(Point a) {
    double tanSlope = (p1.x - p2.x) / (p1.y - p2.y) * -1;
    double slope = (p1.y - p2.y) / (p1.x - p2.x);
    double b = p1.y - (slope * p1.x);
    double tanb = a.y - (tanSlope * a.x);
    double linepx = (tanb - b) / (slope - tanSlope);
    double linepy = (tanSlope * linepx + tanb);
    Point point = Point(linepx, linepy);
    double distance = point.distance_to_point(a);
    return distance;
  }
};

// problem 6
class Triangle {
  public:
  Point p1;
  Point p2;
  Point p3;

  Triangle(const Point &p1, const Point &p2, const Point &p3): p1(p1), p2(p2), p3(p3) {
  }

  double area() {
    double area = 0.5 * (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    return area;
  }
};

// problem 7
class Polygon {
  public:
  std::vector<Point> vp;

  Polygon(const std::vector<Point> &vp): vp(vp) {
  }

  double area() {
    double area = 0;
    for(int i = 1; i < (vp.size() - 1); i++) {
      area += Triangle(vp[0], vp[i], vp[i+1]).area();
    }
    return area;
  }

  double perimeter() {
    double perimeter = 0;
    for(int i = 0; i < vp.size(); i++) {
      perimeter += Line(vp[i], vp[i+1]).length();
    }
    return perimeter;
  }
};

class AUV {
  public:
  std::string name;
  Point position;
  double depth;
  double heading;
  std::array<double, 3> speed;
  double angular_speed;

  AUV(const std::string &name, Point position, double depth, double heading, std::array<double, 3> speed, double angular_speed): name(name), position(position), depth(depth), heading(heading), speed(speed), angular_speed(angular_speed){
  }

  void step(double dt) {
    this->position.x += this->speed[0] * dt;
    this->position.y += this->speed[1] * dt;
    this->depth += this->speed[2] * dt;
  }

  void apply_acceleration(std::array<double, 3> accel, double dt) {
    this->speed[0] += accel[0] * dt;
    this->speed[1] += accel[1] * dt;
    this->speed[2] += accel[2] * dt;
    this->step(dt);
  }

  void apply_angular_acceleration(double angular_acceleration, double dt) {
    this->angular_speed += angular_acceleration * dt;
    this->heading += angular_speed * dt;
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

  std::cout << "The distance from point (" << p.x << ", " << p.y << ") and the origin is " << p.distance_to_origin() << std::endl; 
  std::cout << "The distance from point (" << p.x << ", " << p.y << ") and point (" << p1.x << ", " << p1.y << ") is " << p.distance_to_point(p1) << std::endl;
  std::cout << "The length from of line p-p1 is " << l.length() << std::endl;
  std::cout << "The distance from point p to line l is: " << l.distance_to_point(p3) << std::endl;
  std::cout << "The area of triangle p1, p2, p3 is: " << t.area() << std::endl;
  std::cout << "The area of polygon b is: " << b.area() << std::endl;
  std::cout << "The perimeter of polygon b is: " << b.perimeter() << std::endl;
  return 0;
}