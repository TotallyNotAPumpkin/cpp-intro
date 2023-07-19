#include <iostream>
#include "Triangle.hpp"

Triangle::Triangle(Point p1, Point p2, Point p3): p1(p1), p2(p2), p3(p3) {
}

double Triangle::area() {
    double area = 0.5 * (p1.x() * (p2.y() - p3.y()) + p2.x() * (p3.y() - p1.y()) + p3.x() * (p1.y() - p2.y()));
    return area;
}