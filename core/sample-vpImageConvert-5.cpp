#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<vpRGBa> Ic; // A color image

  // Load a color image from the disk
  vpImageIo::readPPM(Ic, "image.ppm");

  // Only R and B Channels are desired.
  vpImage<unsigned char> R, B;

  // Split Ic color image
  // R and B will be resized in split function if needed
  vpImageConvert::split(Ic, &R, NULL, &B, NULL);

  // Save the the R Channel.
  vpImageIo::writePGM(R, "RChannel.pgm");
}
