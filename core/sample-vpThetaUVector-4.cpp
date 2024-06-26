#include <visp3/core/vpThetaUVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpHomogeneousMatrix M(0, 0, 1., vpMath::rad(10), vpMath::rad(20), vpMath::rad(30));

  double theta;
  vpColVector u;
  M.getRotationMatrix().getThetaUVector().extract(theta, u);
  std::cout << "theta: " << theta << std::endl;
  std::cout << "u    : " << u.t() << std::endl;
}
