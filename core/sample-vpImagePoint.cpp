#include <iostream>

#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImagePoint.h>
#include <visp3/core/vpTime.h>
#include <visp3/core/vpImage.h>
#include <visp3/core/vpColor.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/core/vpMath.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  int niter = 1000000;
  double t1, t2;

  vpImage<unsigned char> I(240, 320);
  I = 255;

#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I);
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I);
#endif

  {
    vpDisplay::display(I);
    vpDisplay::flush(I);

    t1 = vpTime::measureTimeMicros();
    for (int n = 0; n < niter; n++) {
      double i = n%200, j = n%200;
      vpDisplay::displayPoint(I, vpMath::round(i), vpMath::round(j), vpColor::red);
    }
    t2 = vpTime::measureTimeMicros();
    std::cout << "Duree alloc 2 doubles*" << niter << " + display*" << niter << ": "
      << t2-t1 << "us" << std::endl;
    vpDisplay::flush(I);
    //    vpDisplay::getClick(I);
  }

  //---------------------------------------------------------------
  {
    vpDisplay::display(I);
    vpDisplay::flush(I);

    double i, j;
    t1 = vpTime::measureTimeMicros();
    for (int n = 0; n < niter; n++) {
      i = n%200, j = n%200;
      vpDisplay::displayPoint(I, vpMath::round(i), vpMath::round(j), vpColor::red);
    }
    t2 = vpTime::measureTimeMicros();
    std::cout << "Duree alloc 2 doubles + display*" << niter << ": "
      << t2-t1 << "us" << std::endl;
    vpDisplay::flush(I);
    //    vpDisplay::getClick(I);
  }

  //---------------------------------------------------------------
  {
    vpDisplay::display(I);
    vpDisplay::flush(I);

    t1 = vpTime::measureTimeMicros();
    for (int n = 0; n < niter; n++) {
      vpImagePoint ip;
      ip.set_i(n%200);
      ip.set_j(n%200);
      vpDisplay::displayPoint(I, ip, vpColor::red);
    }
    t2 = vpTime::measureTimeMicros();
    std::cout << "Duree alloc vpImagePoint* " << niter << " + display*" << niter << ": "
      << t2-t1 << "us" << std::endl;
    vpDisplay::flush(I);
    //    vpDisplay::getClick(I);
  }

  //---------------------------------------------------------------
  {
    vpDisplay::display(I);
    vpDisplay::flush(I);

    t1 = vpTime::measureTimeMicros();
    vpImagePoint ip;
    for (int n = 0; n < niter; n++) {
      ip.set_i(n%200);
      ip.set_j(n%200);
      vpDisplay::displayPoint(I, ip, vpColor::red);
    }
    t2 = vpTime::measureTimeMicros();
    std::cout << "Duree alloc 1 vpImagePoint + display*" << niter << ": "
      << t2-t1 << "us" << std::endl;
    vpDisplay::flush(I);
    //    vpDisplay::getClick(I);
  }

#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
  return 0;
}
