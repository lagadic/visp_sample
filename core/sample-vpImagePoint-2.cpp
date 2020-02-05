#include <iostream>
#include <visp3/core/vpImagePoint.h>

int main()
{
  vpImagePoint ip(100, 200); // Create an image point with coordinates i=100, j=200
  std::cout << "ip: " << ip << std::endl; // coordinates (100, 200)
  std::cout << "ip+10: " << ip+10 << std::endl; // new coordinates (110, 210)
  std::cout << "ip-10: " << ip-10 << std::endl; // new coordinates (90, 190)
  std::cout << "ip+12.34: " << ip+12.34 << std::endl; // new coordinates (112.34, 212.34)
  std::cout << "ip-12.34: " << ip-12.34 << std::endl; // new coordinates (87.66, 187.66)
  std::cout << "ip*2: " << ip*2 << std::endl; // new coordinates (200, 400)
  std::cout << "ip/2: " << ip/2 << std::endl; // new coordinates (50, 100)

  return 0;
}
