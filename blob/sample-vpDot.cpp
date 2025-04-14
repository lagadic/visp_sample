#include <visp3/core/vpConfig.h>
#include <visp3/blob/vpDot.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DC1394)
  vpImage<unsigned char> I; // Create a gray level image container
  vp1394TwoGrabber g(false); // Create a grabber based on libdc1394-2.x third party lib
  g.acquire(I); // Acquire an image

#if defined(VISP_HAVE_DISPLAY)
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I, 0, 0, "Camera view");
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I, 0, 0, "Camera view");
#endif
#endif
  vpDisplay::display(I);
  vpDisplay::flush(I);

  vpDot blob;
  blob.initTracking(I);
  blob.setGraphics(true);

  while (1) {
    g.acquire(I); // Acquire an image
    vpDisplay::display(I);
    blob.track(I);

    vpDisplay::flush(I);
  }

#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
}
#endif
#endif
}
