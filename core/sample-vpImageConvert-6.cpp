#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>

#if defined(HAVE_OPENCV_IMGCODECS)
#include <opencv2/imgcodecs.hpp>
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION >= 0x020100) && defined(HAVE_OPENCV_IMGCODECS)
  vpImage<unsigned char> Ig; // A greyscale image
  cv::Mat Ip;

  // Read an image on a disk
  vpImageIo::readPGM(Ig, "image.pgm");
  // Convert the vpImage<unsigned char> in to greyscale cv::Mat
  vpImageConvert::convert(Ig, Ip);
  // Treatments on cv::Mat Ip
  //...
  // Save the cv::Mat on the disk
  cv::imwrite("image.pgm", Ip);
#endif
}


