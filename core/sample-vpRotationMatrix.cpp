#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpColVector p1(3), p2(3);
  vpRotationMatrix R;

  p2 = R * p1;

  return 0;
}
