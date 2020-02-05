#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
  vpImage<vpRGBa> I;
  vp1394TwoGrabber g;
  g >> I;
}

