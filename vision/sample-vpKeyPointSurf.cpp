#include <visp3/core/vpImage.h>
#include <visp3/vision/vpKeyPointSurf.h>

int main()
{
#if defined(VISP_HAVE_OPENCV_NONFREE) && (VISP_HAVE_OPENCV_VERSION < 0x030000)
  vpImage<unsigned char> Irefrence;
  vpImage<unsigned char> Icurrent;
  vpKeyPointSurf surf;

  // First grab the reference image Irefrence

  // Build the reference SURF points.
  surf.buildReference(Irefrence);

  // Then grab another image which represents the current image Icurrent

  // Match points between the reference points and the SURF points computed in the current image.
  surf.matchPoint(Icurrent);

  // Display the matched points
  surf.display(Irefrence, Icurrent);

  return (0);
#endif
}

