#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/vision/vpKeyPoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(HAVE_OPENCV_IMGPROC) && \
  ((VISP_HAVE_OPENCV_VERSION < 0x050000) && defined(HAVE_OPENCV_CALIB3D) && defined(HAVE_OPENCV_FEATURES2D)) || \
  ((VISP_HAVE_OPENCV_VERSION >= 0x050000) && defined(HAVE_OPENCV_3D) && defined(HAVE_OPENCV_FEATURES))

  vpImage<unsigned char> Ireference;
  vpImage<unsigned char> Icurrent;

  vpKeyPoint::vpFilterMatchingType filterType = vpKeyPoint::ratioDistanceThreshold;
  vpKeyPoint keypoint("ORB", "ORB", "BruteForce-Hamming", filterType);

  // First grab the reference image Ireference
  // Add your code to load the reference image in Ireference

  // Build the reference ORB points.
  keypoint.buildReference(Ireference);

  // Then grab another image which represents the current image Icurrent

  // Match points between the reference points and the ORB points computed in the current image.
  keypoint.matchPoint(Icurrent);

  // Display the matched points
  keypoint.display(Ireference, Icurrent);
#endif

  return (0);
}
