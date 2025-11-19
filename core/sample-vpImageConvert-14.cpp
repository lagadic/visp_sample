#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_YARP)
  vpImage<vpRGBa> I; // A color image
  // Read an image on a disk
  vpImageIo::read(I, "image.jpg");

  yarp::sig::ImageOf< yarp::sig::PixelRgb > *Iyarp = new yarp::sig::ImageOf< yarp::sig::PixelRgb >();
  // Convert the vpImage<vpRGBa> to a yarp::sig::ImageOf<yarp::sig::PixelRgb>
  vpImageConvert::convert(I, Iyarp);

  // ...
#endif
}
