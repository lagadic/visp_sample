#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    vpImage<unsigned char> I;
    vp1394TwoGrabber g(false); // Don't reset the bus
    g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_FORMAT7_0);
    g.setColorCoding(vp1394TwoGrabber::vpCOLOR_CODING_MONO8);
    g.setAutoShutter(1600*20-1, 1600*20); // Set shutter min and max values
    g.setIsoTransmissionSpeed(vp1394TwoGrabber::vpISO_SPEED_800); // 1394b
    for (; ; )
      g.acquire(I);
  }
  catch (...) { }
#endif
}
