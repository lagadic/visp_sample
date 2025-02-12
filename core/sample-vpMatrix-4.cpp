#include <iostream>

#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix A;
  vpColVector v(3);

  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  A.diag(v);

  std::cout << "A:\n" << A << std::endl;

  // A is now equal to:
  // 1 0 0
  // 0 2 0
  // 0 0 3
}
