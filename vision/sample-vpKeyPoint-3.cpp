#include <visp3/core/vpImage.h>
#include <visp3/vision/vpKeyPoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && defined(HAVE_OPENCV_IMGPROC) && defined(HAVE_OPENCV_FEATURES2D)
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
