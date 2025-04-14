#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    unsigned int ncameras; // Number of cameras on the bus
    vpImage<unsigned char> I;

    vp1394TwoGrabber g;
    ncameras = g.getNumCameras();

    int last = 0;
    if (ncameras > 1)
      last = ncameras-1;

    g.setCamera(last); // To dial with the last camera on the bus
    for (int i = 0; i<10; i++)
      g.acquire(I);// I contains the frame captured by the last camera on the bus
  }
  catch (...) { }
#endif
}
