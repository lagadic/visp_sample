#include <visp3/core/vpThetaUVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpHomogeneousMatrix M(0, 0, 1., vpMath::rad(10), vpMath::rad(20), vpMath::rad(30));

  std::cout << "theta: " << M.getRotationMatrix().getThetaUVector().getTheta() << std::endl;
  std::cout << "u    : " << M.getRotationMatrix().getThetaUVector().getU().t() << std::endl;
}
