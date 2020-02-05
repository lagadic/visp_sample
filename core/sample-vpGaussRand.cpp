#include <iostream>

#include <visp3/core/vpGaussRand.h>

int main()
{
  vpGaussRand noise(0.5, 0);
  for(int i=0; i< 10; i++) {
    std::cout << "noise " << i << ": " << noise() << std::endl;
  }
  return 0;
}
