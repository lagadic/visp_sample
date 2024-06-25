#include <visp3/gui/vpDisplayX.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_X11
  vpImage<unsigned char> I(480, 640);
  vpDisplayX d;
  d.setDownScalingFactor(vpDisplay::SCALE_4); // Display in a 160 by 120 windows size
  d.init(I);
  vpDisplay::display(I);
  vpDisplay::flush(I);
  vpDisplay::getClick(I); // wait for a click to quit
#endif
}
