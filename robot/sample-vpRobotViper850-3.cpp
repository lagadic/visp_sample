#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>
#include <visp3/core/vpCameraParameters.h>

int main()
{
#if defined(VISP_HAVE_VIPER850) && defined(VISP_HAVE_DC1394_2)
  vpImage<unsigned char> I;
  vp1394TwoGrabber g;
  g.acquire(I);

  vpRobotViper850 robot;

  // ...

  vpCameraParameters cam;
  robot.getCameraParameters(cam, I);
  // In cam, you get the intrinsic parameters of the projection model
  // with distorsion.
#endif
}
