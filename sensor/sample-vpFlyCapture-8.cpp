#include <visp3/core/vpConfig.h>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

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
