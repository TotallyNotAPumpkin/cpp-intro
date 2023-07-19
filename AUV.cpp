#include "AUV.hpp"

  AUV::AUV(std::string name, Point position, double depth, double heading, std::array<double, 3> speed, double angular_speed): name(name), position(position), depth(depth), heading(heading), speed(speed), angular_speed(angular_speed){
  }

  void AUV::step(double dt) {
    position.set_x(speed[0] * dt + position.x());
    position.set_y(speed[1] * dt + position.y());
    depth += speed[2] * dt;
  }

  void AUV::apply_acceleration(std::array<double, 3> accel, double dt) {
    speed[0] += accel[0] * dt;
    speed[1] += accel[1] * dt;
    speed[2] += accel[2] * dt;
    step(dt);
  }

  void AUV::apply_angular_acceleration(double angular_acceleration, double dt) {
    angular_speed += angular_acceleration * dt;
    heading += angular_speed * dt;
  }
