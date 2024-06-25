#include <visp3/sensor/vpV4l2Grabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_V4L2
  vpImage<unsigned char> I;
  vpV4l2Grabber g;
  g >> I;
#endif
}
