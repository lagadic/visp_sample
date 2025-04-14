#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/sensor/vpRealSense2.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_REALSENSE2
  vpRealSense2 rs;
  rs.open();
  vpImage<unsigned char> I(rs.getIntrinsics(RS2_STREAM_COLOR).height, rs.getIntrinsics(RS2_STREAM_COLOR).width);
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I);
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I);
#endif
  while (true) {
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
#endif
  return 0;
}
