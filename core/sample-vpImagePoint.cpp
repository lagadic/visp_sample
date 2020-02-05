#include <iostream>

#include <visp3/core/vpImagePoint.h>
#include <visp3/core/vpTime.h>
#include <visp3/core/vpImage.h>
#include <visp3/core/vpColor.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/core/vpMath.h>

int main()
{
  int niter = 1000000;
  double t1, t2;

  vpImage<unsigned char> I(240, 320);
  I = 255;

#ifdef VISP_HAVE_X11
  vpDisplayX d(I);
#elif defined(VISP_HAVE_GDI)
  vpDisplayGDI d(I);
#endif

  {
    vpDisplay::display(I);
    vpDisplay::flush(I);

    t1 = vpTime::measureTimeMicros();
    for(int n=0; n < niter; n ++) {
      double i=n%200, j=n%200;
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
    for(int n=0; n < niter; n ++) {
      i=n%200, j=n%200;
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
    for(int n=0; n < niter; n ++) {
      vpImagePoint ip;
      ip.set_i( n%200 );
      ip.set_j( n%200 );
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
    for(int n=0; n < niter; n ++) {
      ip.set_i( n%200 );
      ip.set_j( n%200 );
      vpDisplay::displayPoint(I, ip, vpColor::red);
    }
    t2 = vpTime::measureTimeMicros();
    std::cout << "Duree alloc 1 vpImagePoint + display*" << niter << ": "
        << t2-t1 << "us" << std::endl;
    vpDisplay::flush(I);
    //    vpDisplay::getClick(I);
  }

  return 0;
}
