#include <iostream>

#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394CMUGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_CMU1394) && defined(VISP_HAVE_DISPLAY)
  std::cout << "ViSP Image acquisition example" <<std::endl;

  vpImage<unsigned char> I;
  vp1394CMUGrabber g;

  g.open(I);
  g.acquire(I);

#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I);
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I);
#endif
  vpDisplay::display(I);

  for (;;) {
    g.acquire(I);
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false)) // a click to exit
      break;
  }

  g.close();
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
#endif
  std::cout << "ViSP exiting..." <<std::endl;
  return 0;
}
