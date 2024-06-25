#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/mbt/vpMbEdgeTracker.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMbEdgeTracker tracker; // Create a model based tracker.
  vpImage<unsigned char> I;
  vpHomogeneousMatrix cMo; // Pose used in entry (has to be defined), then computed using the tracker.

  //acquire an image
  vpImageIo::read(I, "cube.pgm"); // Example of acquisition

  tracker.loadConfigFile("cube.xml"); // Load the configuration of the tracker
  // load the 3d model, to read .wrl model coin is required, if coin is not installed .cao file can be used.
  tracker.loadModel("cube.cao");
  tracker.initFromPose(I, cMo); // initialize the tracker with the given pose.

  while (true) {
    // acquire a new image
    tracker.track(I); // track the object on this image
    tracker.getPose(cMo); // get the pose
  }

  return 0;
}
