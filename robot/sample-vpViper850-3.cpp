#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>
#include <visp3/robot/vpViper850.h>
#include <visp3/robot/vpRobotViper850.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<vpRGBa> I(480, 640);

#ifdef VISP_HAVE_DC1394_2
  vp1394TwoGrabber g;

  // Acquire an image to update image structure
  g.acquire(I);
#endif

#ifdef VISP_HAVE_VIPER850
  vpRobotViper850 robot;
#else
  vpViper850 robot;
#endif

  vpCameraParameters cam;
  // Get the intrinsic camera parameters depending on the image size
  try {
    robot.getCameraParameters(cam, I);
  }
  catch (...) {
    std::cout << "Cannot get camera parameters for image: " << I.getWidth() << " x " << I.getHeight() << std::endl;
  }
  std::cout << "Camera parameters: " << cam << std::endl;
}
