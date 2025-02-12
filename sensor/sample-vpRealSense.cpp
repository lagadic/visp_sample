#include <visp3/core/vpConfig.h>
#ifdef VISP_HAVE_REALSENSE

#include <visp3/sensor/vpRealSense.h>
#include <visp3/gui/vpDisplayFactory.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpRealSense rs;
  rs.open();
  std::cout << rs << std::endl;

  vpImage<vpRGBa> I(rs.getIntrinsics(rs::stream::color).height, rs.getIntrinsics(rs::stream::color).width);
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I);
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I);
#endif

  while (1) {
    rs.acquire(I);
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false))
      break;
  }
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
}

#else
int main() { }
#endif
