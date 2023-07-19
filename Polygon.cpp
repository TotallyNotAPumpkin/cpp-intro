#include <iostream>
#include "Polygon.hpp"

Polygon::Polygon(std::vector<Point> vp): vp(vp) {
  }

double Polygon::area() {
    double area = 0;
    for(int i = 1; i < (vp.size() - 1); i++) {
      area += Triangle(vp[0], vp[i], vp[i+1]).area();
    }
    return area;
  }

double Polygon::perimeter() {
    double perimeter = 0;
    for(int i = 0; i < vp.size(); i++) {
      perimeter += Line(vp[i], vp[i+1]).length();
    }
    return perimeter;
  }