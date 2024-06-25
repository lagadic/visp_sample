#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

#if defined(VISP_HAVE_YARP)
#include <yarp/sig/ImageFile.h>
#endif

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_YARP)
  yarp::sig::ImageOf< yarp::sig::PixelRgb > *Iyarp = new yarp::sig::ImageOf< yarp::sig::PixelRgb >();
  // Read an image on a disk
  yarp::sig::file::read(*Iyarp, "image.pgm");

  // Convert the yarp::sig::ImageOf<yarp::sig::PixelRgb> to a vpImage<vpRGBa>
  vpImage<vpRGBa> I;
  vpImageConvert::convert(Iyarp, I);

  // ...
#endif
}
