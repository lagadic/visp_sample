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
    vp1394TwoGrabber g;
    ncameras = g.getNumCameras();
    vpImage<unsigned char> *I = new vpImage<unsigned char>[ncameras];

    // If the first camera supports vpVIDEO_MODE_640x480_YUV422 video mode
    g.setCamera(0);
    g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_640x480_YUV422);

    if (ncameras >= 2) {
      // If the second camera support 30 fps acquisition
      g.setCamera(1);
      g.setFramerate(vp1394TwoGrabber::vpFRAMERATE_30);
    }

    for (int i = 0; i<10; i++) {
      for (unsigned int camera = 0; camera < ncameras; camera++) {
        g.setCamera(camera);
        g.acquire(I[camera]);
      }
    }
    delete[] I;
  }
  catch (...) { }
#endif
}
