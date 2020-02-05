#include <visp3/core/vpImage.h>
#include <visp3/vision/vpKeyPoint.h>

int main()
{
#if (VISP_HAVE_OPENCV_VERSION >= 0x020300)
  vpImage<unsigned char> Irefrence;
  vpImage<unsigned char> Icurrent;

  vpKeyPoint::vpFilterMatchingType filterType = vpKeyPoint::ratioDistanceThreshold;
  vpKeyPoint keypoint("ORB", "ORB", "BruteForce-Hamming", filterType);

  // First grab the reference image Irefrence
  // Add your code to load the reference image in Ireference

  // Build the reference ORB points.
  keypoint.buildReference(Irefrence);

  // Then grab another image which represents the current image Icurrent

  // Match points between the reference points and the ORB points computed in the current image.
  keypoint.matchPoint(Icurrent);

  // Display the matched points
  keypoint.display(Irefrence, Icurrent);
#endif

  return (0);
}
