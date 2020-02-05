#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpImage.h>

int main()
{
  vpImage<unsigned char> I(480, 640);
  double u0 = I.getWidth()  / 2.;
  double v0 = I.getHeight() / 2.;
  double px = 600;
  double py = 600;
  vpCameraParameters cam;
  cam.initPersProjWithoutDistortion(px, py, u0, v0);
  cam.computeFov(I.getWidth(), I.getHeight());
  std::cout << cam << std::endl;
  std::cout << "Field of view (horizontal: " << vpMath::deg(cam.getHorizontalFovAngle())
            << " and vertical: " << vpMath::deg(cam.getVerticalFovAngle())
            << " degrees)" << std::endl;
}
