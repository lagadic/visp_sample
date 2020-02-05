#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION < 0x020408)
  vpImage<unsigned char> Ig; // A grayscale image
  IplImage* Ip;

  // Read an image on a disk with openCV library
  Ip = cvLoadImage("image.pgm", CV_LOAD_IMAGE_GRAYSCALE);
  // Convert the grayscale IplImage into vpImage<unsigned char>
  vpImageConvert::convert(Ip, Ig);

  // ...

  // Release Ip header and data
  cvReleaseImage(&Ip);
#endif
}
