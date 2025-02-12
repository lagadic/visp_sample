#include <visp3/core/vpConfig.h>
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
  yarp::sig::ImageOf< yarp::sig::PixelMono > *Iyarp = new yarp::sig::ImageOf< yarp::sig::PixelMono >();
  // Read an image on a disk
  yarp::sig::file::read(*Iyarp, "image.pgm");

  // Convert the yarp::sig::ImageOf<yarp::sig::PixelMono> to a vpImage<unsigned char>
  vpImage<unsigned char> I;
  vpImageConvert::convert(Iyarp, I);

  // ...
#endif
}
