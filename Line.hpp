#pragma once
#include "Point.hpp"

class Line {
    private:
    ::Point p1;
    ::Point p2;

    public:
    Line(const Point &p1, const Point &p2);
    double length();
    double distance_to_point(::Point a);
};
