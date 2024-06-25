#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/io/vpImageIo.h>


#if defined(HAVE_OPENCV_IMGCODECS)
#include <opencv2/imgcodecs.hpp>
#endif

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && defined(HAVE_OPENCV_IMGPROC) && defined(HAVE_OPENCV_IMGCODECS)
  vpImage<vpRGBa> Ic; // A color image
  cv::Mat Ip;

  // Read an image on a disk with openCV library
  Ip = cv::imread("image.pgm", 1);// second parameter > 0 for a RGB encoding.
  // Convert the grayscale cv::Mat into vpImage<vpRGBa>
  vpImageConvert::convert(Ip, Ic);

  // ...
#endif
}
