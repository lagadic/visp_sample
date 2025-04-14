#include <visp3/core/vpConfig.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpImage.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> I(480, 640);
  vpCameraParameters cam;
  double hfov = vpMath::rad(56);
  double vfov = vpMath::rad(43);
  cam.initFromFov(I.getWidth(), I.getHeight(), hfov, vfov);

  std::cout << cam << std::endl;
  std::cout << "Field of view (horizontal: " << vpMath::deg(cam.getHorizontalFovAngle())
    << " and vertical: " << vpMath::deg(cam.getVerticalFovAngle()) << " degrees)" << std::endl;
}
