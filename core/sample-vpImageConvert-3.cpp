#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION < 0x020408)
  vpImage<vpRGBa> Ic; // A color image
  IplImage* Ip = NULL;

  // Read an image on a disk
  vpImageIo::readPPM(Ic, "image.ppm");
  // Convert the vpImage<vpRGBa> in to color IplImage
  vpImageConvert::convert(Ic, Ip);
  // Treatments on IplImage
  //...
  // Save the IplImage on the disk
  cvSaveImage("Ipl.ppm", Ip);

  //Release Ip header and data
  cvReleaseImage(&Ip);
#endif
}


