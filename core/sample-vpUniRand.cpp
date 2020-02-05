#include <iostream>
#include <visp3/core/vpUniRand.h>

int main()
{
  vpUniRand r;
  for(unsigned int i=0;i<10;++i)
    std::cout << 5*r() << std::endl;
}  

