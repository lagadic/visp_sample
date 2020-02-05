#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>
#include <visp3/robot/vpRingLight.h>

int main()
{
#if defined(VISP_HAVE_PARPORT) && defined(VISP_HAVE_DC1394_2)
  vp1394TwoGrabber g; // Firewire framegrabber based on libdc1394-2.x third party lib
  vpImage<unsigned char> I;

  vpRingLight light; // Open the device to access to the ring light.

  for (int i=0; i < 10; i++) {
    light.pulse(); // Send a pulse to the lighting system
    g.acquire(I); // Acquire an image
  }
#endif
}
