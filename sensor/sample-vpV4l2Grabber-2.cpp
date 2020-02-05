#include <visp3/sensor/vpV4l2Grabber.h>

int main()
{
#ifdef VISP_HAVE_V4L2
  vpImage<unsigned char> I;
  vpV4l2Grabber g;
  g >> I;
#endif
}

