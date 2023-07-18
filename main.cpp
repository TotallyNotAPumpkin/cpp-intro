#include <iostream>

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
  return 0;
}

