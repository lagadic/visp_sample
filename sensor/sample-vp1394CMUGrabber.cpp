#include <iostream>

#include <visp3/core/vpImage.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/sensor/vp1394CMUGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_CMU1394)
  std::cout << "ViSP Image acquisition example" <<std::endl;

  vpImage<unsigned char> I;
  vp1394CMUGrabber g;

  g.open(I);
  g.acquire(I);

  vpDisplayOpenCV d(I);
  vpDisplay::display(I);

  for (;;) {
    g.acquire(I);
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false)) // a click to exit
      break;
  }

  g.close();
#endif
  std::cout << "ViSP exiting..." <<std::endl;
  return 0;
}
