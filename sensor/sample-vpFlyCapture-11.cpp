#include <visp3/core/vpConfig.h>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_FLYCAPTURE
  vpImage<vpRGBa> I;
  vpFlyCaptureGrabber g;
  g >> I;
#endif
}
