#include <visp3/blob/vpDot2.h>
#include <visp3/core/vpImage.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  vpImage<unsigned char> I; // Create a gray level image container
  vp1394TwoGrabber g(false); // Create a grabber based on libdc1394-2.x third party lib
  g.acquire(I); // Acquire an image

#if defined(VISP_HAVE_X11)
  vpDisplayX d(I, 0, 0, "Camera view");
#endif
  vpDisplay::display(I);
  vpDisplay::flush(I);

  vpDot2 blob;
  blob.initTracking(I);
  blob.setGraphics(true);

  while(1) {
    g.acquire(I); // Acquire an image
    vpDisplay::display(I);
    blob.track(I);

    vpDisplay::flush(I);
  }
#endif
}
