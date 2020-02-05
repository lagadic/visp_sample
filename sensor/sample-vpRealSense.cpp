#include <visp3/core/vpConfig.h>
#ifdef VISP_HAVE_REALSENSE

#include <visp3/sensor/vpRealSense.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayX.h>

int main()
{
  vpRealSense rs;
  rs.open();
  std::cout << rs << std::endl;

  vpImage<vpRGBa> I(rs.getIntrinsics(rs::stream::color).height, rs.getIntrinsics(rs::stream::color).width);
#ifdef VISP_HAVE_X11
  vpDisplayX d(I);
#elif defined(VISP_HAVE_GDI)
  vpDisplayGDI d(I);
#endif

  while (1) {
    rs.acquire(I);
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false))
      break;
  }
}

#else
int main() {}
#endif

