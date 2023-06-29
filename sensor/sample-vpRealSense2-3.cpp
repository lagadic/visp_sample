#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/sensor/vpRealSense2.h>

int main() {
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
#ifdef VISP_HAVE_X11
  vpDisplayX dc(Ic, 0, 0, "Color");
  vpDisplayX di(Ii, 100, 100, "Infrared");
#elif defined(VISP_HAVE_GDI)
  vpDisplayGDI dc(Ic, 0, 0, "Color");
  vpDisplayGDI di(Ii, 100, 100, "Infrared");
#endif
  while (true) {
    rs.acquire((unsigned char *) Ic.bitmap, NULL, NULL, Ii.bitmap);
    vpDisplay::display(Ic);
    vpDisplay::display(Ii);
    vpDisplay::flush(Ic);
    vpDisplay::flush(Ii);
    if (vpDisplay::getClick(Ic, false) || vpDisplay::getClick(Ii, false))
      break;
  }
#endif
  return 0;
}

