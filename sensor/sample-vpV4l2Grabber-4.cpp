#include <visp3/core/vpConfig.h>
#include <visp3/sensor/vpV4l2Grabber.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/gui/vpDisplayFactory.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_V4L2) && defined(VISP_HAVE_DISPLAY)
  //vpImage<unsigned char> I;
  vpImage<vpRGBa> I;
  vpRect roi(0, 0, 320, 240);
  //vpRect roi(320, 240, 320, 240);

  vpV4l2Grabber g;
//g.setPixelFormat (vpV4l2Grabber::V4L2_GREY_FORMAT);
//g.setPixelFormat (vpV4l2Grabber::V4L2_RGB32_FORMAT);
//g.setPixelFormat (vpV4l2Grabber::V4L2_BGR24_FORMAT); // tested
//g.setPixelFormat (vpV4l2Grabber::V4L2_RGB24_FORMAT); // tested
//g.setPixelFormat (vpV4l2Grabber::V4L2_YUYV_FORMAT); // tested
//g.setFramerate(vpV4l2Grabber::framerate_25fps);
//  g.setScale(1);
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display;
#else
  vpDisplay *display = nullptr;
#endif
  bool first = true;
  while (1) {
    g.acquire(I, roi);
    if (first) {
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
      display = vpDisplayFactory::createDisplay(I);
#else
      display = vpDisplayFactory::allocateDisplay(I);
#endif
      first = false;
    }
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false))
      break;
  }
  vpImageIo::write(I, "image.pgm"); // Save the last image
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
#endif
}
