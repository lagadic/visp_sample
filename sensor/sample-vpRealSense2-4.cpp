
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImageConvert.h>
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
  config.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_RGBA8, 30);
  config.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);
  config.enable_stream(RS2_STREAM_INFRARED, 640, 480, RS2_FORMAT_Y8, 30);
  rs.open(config);
  vpImage<vpRGBa> Ic(rs.getIntrinsics(RS2_STREAM_COLOR).height, rs.getIntrinsics(RS2_STREAM_COLOR).width);
  vpImage<uint16_t> Id_raw(rs.getIntrinsics(RS2_STREAM_DEPTH).height, rs.getIntrinsics(RS2_STREAM_DEPTH).width);
  vpImage<vpRGBa> Id(rs.getIntrinsics(RS2_STREAM_DEPTH).height, rs.getIntrinsics(RS2_STREAM_DEPTH).width);
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> dc = vpDisplayFactory::createDisplay(Ic, 0, 0, "Color");
  std::shared_ptr<vpDisplay> dd = vpDisplayFactory::createDisplay(Id, 100, 100, "Depth aligned to color");
#else
  vpDisplay *dc = vpDisplayFactory::allocateDisplay(Ic, 0, 0, "Color");
  vpDisplay *dd = vpDisplayFactory::allocateDisplay(Id, 100, 100, "Depth aligned to color");
#endif
  rs2::align align_to(RS2_STREAM_COLOR);
  while (true) {
    rs.acquire((unsigned char *)Ic.bitmap, (unsigned char *)Id_raw.bitmap, NULL, NULL, &align_to);
    vpImageConvert::createDepthHistogram(Id_raw, Id);
    vpDisplay::display(Ic);
    vpDisplay::display(Id);
    vpDisplay::flush(Ic);
    vpDisplay::flush(Id);
    if (vpDisplay::getClick(Ic, false) || vpDisplay::getClick(Id, false))
      break;
  }
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (dc != nullptr) {
    delete dc;
  }
  if (dd != nullptr) {
    delete dd;
  }
#endif
#endif
  return 0;
}
