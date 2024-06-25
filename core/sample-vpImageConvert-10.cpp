#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_YARP)
  vpImage<unsigned char> I; // A mocochrome image
  // Read an image on a disk
  vpImageIo::readPGM(I, "image.pgm");

  yarp::sig::ImageOf< yarp::sig::PixelMono > *Iyarp = new yarp::sig::ImageOf< yarp::sig::PixelMono >();
  // Convert the vpImage\<unsigned char\> to a yarp::sig::ImageOf\<yarp::sig::PixelMono\>
  vpImageConvert::convert(I, Iyarp);

  // ...
#endif
}
