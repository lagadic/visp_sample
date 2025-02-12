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
  rs2::config config;
  config.enable_stream(RS2_STREAM_COLOR, 1920, 1080, RS2_FORMAT_RGBA8, 30);
  config.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);
  config.enable_stream(RS2_STREAM_INFRARED, 640, 480, RS2_FORMAT_Y8, 30);
  rs.open(config);
  vpImage<vpRGBa> Ic(rs.getIntrinsics(RS2_STREAM_COLOR).height, rs.getIntrinsics(RS2_STREAM_COLOR).width);
  vpImage<unsigned char> Ii(rs.getIntrinsics(RS2_STREAM_INFRARED).height,
                            rs.getIntrinsics(RS2_STREAM_INFRARED).width);

#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> dc = vpDisplayFactory::createDisplay(Ic, 0, 0, "Color");
  std::shared_ptr<vpDisplay> di = vpDisplayFactory::createDisplay(Ii, 100, 100, "Infrared");
#else
  vpDisplay *dc = vpDisplayFactory::allocateDisplay(Ic, 0, 0, "Color");
  vpDisplay *di = vpDisplayFactory::allocateDisplay(Ii, 100, 100, "Infrared");
#endif
  while (true) {
    rs.acquire((unsigned char *)Ic.bitmap, NULL, NULL, Ii.bitmap);
    vpDisplay::display(Ic);
    vpDisplay::display(Ii);
    vpDisplay::flush(Ic);
    vpDisplay::flush(Ii);
    if (vpDisplay::getClick(Ic, false) || vpDisplay::getClick(Ii, false))
      break;
  }
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (dc != nullptr) {
    delete dc;
  }
  if (di != nullptr) {
    delete di;
  }
#endif
#endif
  return 0;
}
