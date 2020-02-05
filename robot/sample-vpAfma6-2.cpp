#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>
#include <visp3/robot/vpRobotAfma6.h>
#include <visp3/core/vpCameraParameters.h>

int main()
{
#if defined(VISP_HAVE_DC1394_2) && defined(VISP_HAVE_AFMA6)
  vpImage<unsigned char> I;
  vp1394TwoGrabber g;

  // Acquire an image to update image structure
  g.acquire(I) ;

  vpRobotAfma6 robot;
  vpCameraParameters cam ;
  // Get the intrinsic camera parameters depending on the image size
  // Camera parameters are read from
  // /udd/fspindle/robot/Afma6/current/include/const_camera_Afma6.xml
  // if VISP_HAVE_ACCESS_TO_NAS and VISP_HAVE_XML2 macros are defined in vpConfig.h file
  try {
    robot.getCameraParameters (cam, I.getWidth(), I.getHeight());
  }
  catch(...) {
    std::cout << "Cannot get camera parameters for image: " << I.getWidth() << " x " << I.getHeight() << std::endl;
  }
  std::cout << "Camera parameters: " << cam << std::endl;
#endif
}
