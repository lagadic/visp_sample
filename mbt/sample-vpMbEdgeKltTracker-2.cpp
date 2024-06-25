#include <visp3/mbt/vpMbEdgeKltTracker.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/gui/vpDisplayX.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && defined(HAVE_OPENCV_IMGPROC) && defined(HAVE_OPENCV_VIDEO)
  vpMbEdgeKltTracker tracker; // Create an hybrid model based tracker.
  vpImage<unsigned char> I;
  vpHomogeneousMatrix cMo; // Pose used to display the model.
  vpCameraParameters cam;

  // Acquire an image
  vpImageIo::readPGM(I, "cube.pgm");

#if defined VISP_HAVE_X11
  vpDisplayX display;
  display.init(I, 100, 100, "Mb Hybrid Tracker");
#endif

  tracker.loadConfigFile("cube.xml"); // Load the configuration of the tracker
  tracker.getCameraParameters(cam); // Get the camera parameters used by the tracker (from the configuration file).
  tracker.loadModel("cube.cao"); // load the 3d model, to read .wrl model coi is required, if coin is not installed .cao file can be used.

  while (true) {
    // acquire a new image
    // Get the pose using any method
    vpDisplay::display(I);
    tracker.display(I, cMo, cam, vpColor::darkRed, 1, true); // Display the model at the computed pose.
    vpDisplay::flush(I);
  }

  return 0;
#endif
}
