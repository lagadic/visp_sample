#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  vpFlyCaptureGrabber g;

  g.setCameraIndex(0);
  g.connect();

  bool power = g.getCameraPower();
  std::cout << "Camera is powered: " << ((power == true) ? "on" : "off") << std::endl;

  if (power)
    g.setCameraPower(false); // Power off the camera
#endif
}

