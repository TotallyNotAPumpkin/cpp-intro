#include "Line.hpp"
#include <cmath>

Line::Line(const Point &p1, const Point &p2): p1(p1), p2(p2) {

  }

double Line::length() {
    return sqrt(pow((p1.y()-p2.y()), 2) + pow((p1.x()-p2.x()), 2));
}

double Line::distance_to_point(Point a) {
    double tanSlope = (p1.x() - p2.x()) / (p1.y() - p2.y()) * -1;
    double slope = (p1.y() - p2.y()) / (p1.x() - p2.x());
    double b = p1.y() - (slope * p1.x());
    double tanb = a.y() - (tanSlope * a.x());
    double linepx = (tanb - b) / (slope - tanSlope);
    double linepy = (tanSlope * linepx + tanb);
    Point point = Point(linepx, linepy);
    double distance = point.distance_to_point(a);
    return distance;
}