#pragma once
#include <vector>
#include "Triangle.hpp"
#include "Line.hpp"

class Polygon{
private:
std::vector<Point> vp;

public:
Polygon(std::vector<Point> vp);
double area();
double perimeter();
};