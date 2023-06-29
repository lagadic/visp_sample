#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
#ifdef VISP_HAVE_DC1394_2
  vpImage<vpRGBa> I;
  vp1394TwoGrabber g;
  g >> I;
#endif
}

