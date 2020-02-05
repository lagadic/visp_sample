#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION < 0x020408)
  vpImage<unsigned char> Ig; // A greyscale image
  IplImage* Ip = NULL;

  // Read an image on a disk
  vpImageIo::readPGM(Ig, "image.pgm");
  // Convert the vpImage<unsigned char> in to greyscale IplImage
  vpImageConvert::convert(Ig, Ip);
  // Treatments on IplImage Ip
  //...
  // Save the IplImage on the disk
  cvSaveImage("Ipl.pgm", Ip);

  //Release Ip header and data
  cvReleaseImage(&Ip);
#endif
}

