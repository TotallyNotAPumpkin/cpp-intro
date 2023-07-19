#pragma once
#include <iostream>
#include "Point.hpp"
#include <array>

class AUV {
  private:
  std::string name;
  Point position;
  double depth;
  double heading;
  std::array<double, 3> speed;
  double angular_speed;

public:
  AUV(std::string name, Point position, double depth, double heading, std::array<double, 3> speed, double angular_speed);
  void step(double dt);
  void apply_acceleration(std::array<double, 3> accel, double dt);
  void apply_angular_acceleration(double angular_acceleration, double dt);
};