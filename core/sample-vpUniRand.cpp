#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpUniRand.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpUniRand r;
  for (unsigned int i = 0; i<10; ++i)
    std::cout << 5*r() << std::endl;
}
