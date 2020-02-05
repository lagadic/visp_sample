#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    unsigned int ncameras; // Number of cameras on the bus
    vp1394TwoGrabber g;
    ncameras = g.getNumCameras();
    g.setCamera(ncameras-1); // To dial with the last camera on the bus
    g.resetBus(); // Reset the bus attached to "ncameras-1"
  }
  catch(...) {}
#endif
}
