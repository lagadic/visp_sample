#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageFilter.h>

int main()
{
#if (VISP_HAVE_OPENCV_VERSION >= 0x020100) && (VISP_HAVE_OPENCV_VERSION < 0x030000) // Cany uses OpenCV >=2.1.0 and < 3.0.0
  // Constants for the Canny operator.
  const unsigned int gaussianFilterSize = 5;
  const double thresholdCanny = 15;
  const unsigned int apertureSobel = 3;

  // Image for the Canny edge operator
  vpImage<unsigned char> Isrc;
  vpImage<unsigned char> Icanny;

  //First grab the source image Isrc.

  //Apply the Canny edge operator and set the Icanny image.
  vpImageFilter::canny(Isrc, Icanny, gaussianFilterSize, thresholdCanny, apertureSobel);
#endif
  return (0);
}

