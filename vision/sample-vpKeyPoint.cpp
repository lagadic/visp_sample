#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/vision/vpKeyPoint.h>

#if defined(HAVE_OPENCV_IMGPROC) && \
  ((VISP_HAVE_OPENCV_VERSION < 0x050000) && defined(HAVE_OPENCV_CALIB3D) && defined(HAVE_OPENCV_FEATURES2D)) || \
  ((VISP_HAVE_OPENCV_VERSION >= 0x050000) && defined(HAVE_OPENCV_3D) && defined(HAVE_OPENCV_FEATURES))

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  //Test Matching side by side
  vpImage<unsigned char> IRef, I, IMatching;
  vpImageIo::read(IRef, "box.png");
  vpImageIo::read(I, "box_in_scene.png");

  const std::string detectorName = "ORB";
  const std::string extractorName = "ORB";
  //Hamming distance must be used with ORB
  const std::string matcherName = "BruteForce-Hamming";
  vpKeyPoint::vpFilterMatchingType filterType = vpKeyPoint::ratioDistanceThreshold;

  vpKeyPoint keypoint(detectorName, extractorName, matcherName, filterType);

  std::cout << "Reference keypoints=" << keypoint.buildReference(IRef) << std::endl;
  std::cout << "Matches=" << keypoint.matchPoint(I) << std::endl;

  //Create the matching image with appropriate size
  keypoint.createImageMatching(IRef, I, IMatching);

#if defined(VISP_HAVE_DISPLAY)
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(IMatching, 0, 0, "Image matching");
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(IMatching, 0, 0, "Image matching");
#endif
#else
  std::cout << "No image viewer is available..." << std::endl;
  return -1;
#endif

  //Insert the two images for a side-by-side display
  keypoint.insertImageMatching(IRef, I, IMatching);
  vpDisplay::display(IMatching);
  //Display the matching between the keypoints detected in the current image
  //and those detected in the reference image
  keypoint.displayMatching(IRef, IMatching);
  vpDisplay::flush(IMatching);
  vpDisplay::getClick(IMatching, true);

#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
  return 0;
}
#else
int main()
{
  return 0;
}
#endif
