#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

#if defined(HAVE_OPENCV_IMGCODECS)
#include <opencv2/imgcodecs.hpp>
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && defined(HAVE_OPENCV_IMGPROC) && defined(HAVE_OPENCV_IMGCODECS)
  vpImage<unsigned char> Ig; // A grayscale image
  cv::Mat Ip;

  // Read an image on a disk with openCV library
  Ip = cv::imread("image.pgm", 0);// second parameter = 0 for a gray level.
  // Convert the grayscale cv::Mat into vpImage<unsigned char>
  vpImageConvert::convert(Ip, Ig);

  // ...
#endif
}


