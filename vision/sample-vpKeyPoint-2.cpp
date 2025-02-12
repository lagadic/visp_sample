#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/vision/vpKeyPoint.h>
#include <visp3/vision/vpHomography.h>
#include <visp3/core/vpCameraParameters.h>

#if defined(HAVE_OPENCV_IMGPROC) && \
  ((VISP_HAVE_OPENCV_VERSION < 0x050000) && defined(HAVE_OPENCV_CALIB3D) && defined(HAVE_OPENCV_FEATURES2D)) || \
  ((VISP_HAVE_OPENCV_VERSION >= 0x050000) && defined(HAVE_OPENCV_3D) && defined(HAVE_OPENCV_FEATURES))

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> IRef, I, IMatching;
  vpImageIo::read(IRef, "box.png");
  vpImageIo::read(I, "box_in_scene.png");

  const std::string detectorName = "ORB";
  const std::string extractorName = "ORB";
  //Hamming distance must be used with ORB
  const std::string matcherName = "BruteForce-Hamming";
  vpKeyPoint::vpFilterMatchingType filterType = vpKeyPoint::ratioDistanceThreshold;

  vpKeyPoint keypoint(detectorName, extractorName, matcherName, filterType);
  keypoint.setMatchingRatioThreshold(0.8);

  std::cout << "Reference keypoints=" << keypoint.buildReference(IRef) << std::endl;

  unsigned int nb_matches = keypoint.matchPoint(I);
  std::cout << "Matches=" << nb_matches << std::endl;

  //Create the matching image with appropriate size
  keypoint.createImageMatching(IRef, I, IMatching);

#if defined(VISP_HAVE_DISPLAY)
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(IMatching, 0, 0, "Image matching and box location detection");
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(IMatching, 0, 0, "Image matching and box location detection");
#endif
#else
  std::cout << "No image viewer is available..." << std::endl;
  return -1;
#endif

  //Insert the two images for a side-by-side display
  keypoint.insertImageMatching(IRef, I, IMatching);
  vpDisplay::display(IMatching);

  //Compute a Ransac homography to find the box
  vpCameraParameters cam(600, 600, I.getWidth() / 2, I.getHeight() / 2);
  vpHomography H;

  //List of keypoints coordinates in normalized camera frame in reference image
  std::vector<double> mPref_x(nb_matches), mPref_y(nb_matches);
  //List of keypoints coordinates in normalized camera frame in current image
  std::vector<double> mPcur_x(nb_matches), mPcur_y(nb_matches);
  //List of inliers
  std::vector<bool> inliers(nb_matches);
  for (unsigned int i = 0; i < nb_matches; i++) {
    //Pair of matched keypoints
    vpImagePoint matched_ref, matched_cur;
    keypoint.getMatchedPoints(i, matched_ref, matched_cur);
    //Convert the coordinate in pixel frame to the normalized camera frame
    vpPixelMeterConversion::convertPoint(cam, matched_ref, mPref_x[i], mPref_y[i]);
    vpPixelMeterConversion::convertPoint(cam, matched_cur, mPcur_x[i], mPcur_y[i]);
  }

  double residual;
  //At least 50% of the matched points must have a positive vote to consider
  //the solution picked valid
  unsigned int nb_inliers_consensus = (unsigned int)mPref_x.size() / 2;
  //Maximum error (in meter) allowed to consider a point as an inlier
  double ransac_threshold = 2.0 / cam.get_px();
  vpHomography::ransac(mPref_x, mPref_y, mPcur_x, mPcur_y, H, inliers,
                       residual, nb_inliers_consensus, ransac_threshold, true);

  //Defines the 4 corners of the box in the reference and the current images
  vpImagePoint corner_ref[4], corner_cur[4];
  corner_ref[0].set_ij(0, 0);
  corner_ref[1].set_ij(0, IRef.getWidth());
  corner_ref[2].set_ij(IRef.getHeight(), IRef.getWidth());
  corner_ref[3].set_ij(IRef.getHeight(), 0);

  //Project the image point such as corner_cur[i] = H . corner_ref[i]
  for (int i = 0; i < 4; i++) {
    corner_cur[i] = vpHomography::project(cam, H, corner_ref[i]);
    //Add u-offset (width of the reference image)
    corner_cur[i].set_u(corner_cur[i].get_u() + IRef.getWidth());
  }

  //Display the bounding box of the box in the current image
  vpDisplay::displayLine(IMatching, corner_cur[0], corner_cur[1], vpColor::blue, 2);
  vpDisplay::displayLine(IMatching, corner_cur[1], corner_cur[2], vpColor::blue, 2);
  vpDisplay::displayLine(IMatching, corner_cur[2], corner_cur[3], vpColor::blue, 2);
  vpDisplay::displayLine(IMatching, corner_cur[3], corner_cur[0], vpColor::blue, 2);

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
