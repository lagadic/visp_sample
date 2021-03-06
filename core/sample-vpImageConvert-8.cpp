#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION >= 0x020100)
  vpImage<unsigned char> Ig; // A grayscale image
  cv::Mat Ip;

  // Read an image on a disk with openCV library
  Ip = cv::imread("image.pgm", 0);// second parameter = 0 for a gray level.
  // Convert the grayscale cv::Mat into vpImage<unsigned char>
  vpImageConvert::convert(Ip, Ig);

  // ...
#endif
}


