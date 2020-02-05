#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/vision/vpKeyPoint.h>

#if (VISP_HAVE_OPENCV_VERSION >= 0x020101)
int main() {
  //Test Matching side by side
  vpImage<unsigned char> IRef, I, IMatching;
  vpImageIo::read(IRef, "box.png");
  vpImageIo::read(I, "box_in_scene.png");

  const std::string detectorName = "ORB";
  const std::string extractorName = "ORB";
  //Hamming distance must be used with ORB
  const std::string matcherName = "BruteForce-Hamming";
  vpKeyPoint::vpFilterMatchingType filterType =
      vpKeyPoint::ratioDistanceThreshold;

  vpKeyPoint keypoint(detectorName, extractorName, matcherName, filterType);

  std::cout << "Reference keypoints=" << keypoint.buildReference(IRef) << std::endl;
  std::cout << "Matches=" << keypoint.matchPoint(I) << std::endl;

  //Create the matching image with appropriate size
  keypoint.createImageMatching(IRef, I, IMatching);

#if defined(VISP_HAVE_X11)
  vpDisplayX display(IMatching, 0, 0, "Image matching");
#elif defined(VISP_HAVE_GDI)
  vpDisplayGDI display(IMatching, 0, 0, "Image matching");
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

  return 0;
}
#else
int main() {
  return 0;
}
#endif
