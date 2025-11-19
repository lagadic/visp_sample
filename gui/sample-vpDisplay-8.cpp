#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_DISPLAY
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay();
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay();
#endif
  vpImage<unsigned char> I(480, 640);
  display->setDownScalingFactor(vpDisplay::SCALE_4); // Display in a 160 by 120 windows size
  display->init(I);
  vpDisplay::display(I);
  vpDisplay::flush(I);
  vpDisplay::getClick(I); // wait for a click to quit
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
#endif
}
