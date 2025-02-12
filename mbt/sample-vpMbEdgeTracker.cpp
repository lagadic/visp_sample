#include <visp3/core/vpConfig.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpImage.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/mbt/vpMbEdgeTracker.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMbEdgeTracker tracker; // Create a model based tracker.
  vpImage<unsigned char> I;
  vpHomogeneousMatrix cMo; // Pose computed using the tracker.
  vpCameraParameters cam;

  // Acquire an image
  vpImageIo::read(I, "cube.pgm");
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I, 100, 100, "Mb Edge Tracker");
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I, 100, 100, "Mb Edge Tracker");
#endif

#if defined VISP_HAVE_PUGIXML
  tracker.loadConfigFile("cube.xml"); // Load the configuration of the tracker
#endif
  tracker.getCameraParameters(cam);   // Get the camera parameters used by the tracker (from the configuration file).
  tracker.loadModel("cube.cao");      // Load the 3d model in cao format. No 3rd party library is required
  // Initialise manually the pose by clicking on the image points associated to the 3d points contained in the
  // cube.init file.
  tracker.initClick(I, "cube.init");

  while (true) {
    // Acquire a new image
    vpDisplay::display(I);
    tracker.track(I);     // Track the object on this image
    tracker.getPose(cMo); // Get the pose

    tracker.display(I, cMo, cam, vpColor::darkRed, 1); // Display the model at the computed pose.
    vpDisplay::flush(I);
  }

#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif

  return 0;
}
