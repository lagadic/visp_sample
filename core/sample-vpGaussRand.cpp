#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpGaussRand.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpGaussRand noise(0.5, 0);
  for (int i = 0; i< 10; i++) {
    std::cout << "noise " << i << ": " << noise() << std::endl;
  }
  return 0;
}
