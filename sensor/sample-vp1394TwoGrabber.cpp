#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vp1394TwoGrabber.h>
#include <visp3/core/vpException.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    vpImage<unsigned char> I; // Create a gray level image container
    bool reset = true; // Enable bus reset during construction (default)
    vp1394TwoGrabber g(reset); // Create a grabber based on libdc1394-2.x third party lib
    g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_640x480_MONO8);
    g.setFramerate(vp1394TwoGrabber::vpFRAMERATE_60);

    g.acquire(I);                        // Acquire an image
    vpImageIo::writePGM(I, "image.pgm"); // Write image on the disk
  }
  catch (...) { }
#endif
}
