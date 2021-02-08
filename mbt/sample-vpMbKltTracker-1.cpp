#include <visp3/mbt/vpMbKltTracker.h>
#include <visp3/core/vpImage.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpXmlParser.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#if defined(VISP_HAVE_MODULE_KLT) && (defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION >= 0x020100))
  vpMbKltTracker tracker; // Create a model based tracker via Klt Points.
  vpImage<unsigned char> I;
  vpHomogeneousMatrix cMo; // Pose used in entry (has to be defined), then computed using the tracker.

  //acquire an image
  vpImageIo::readPGM(I, "cube.pgm"); // Example of acquisition

#if defined VISP_HAVE_XML2
  tracker.loadConfigFile("cube.xml"); // Load the configuration of the tracker
#endif
  tracker.loadModel("cube.cao"); // load the 3d model, to read .wrl model coi is required, if coin is not installed .cao file can be used.
  tracker.initFromPose(I, cMo); // initialise the tracker with the given pose.

  while(true){
    // acquire a new image
    tracker.track(I); // track the object on this image
    tracker.getPose(cMo); // get the pose
  }

  // Cleanup memory allocated by xml library used to parse the xml config file in vpMbKltTracker::loadConfigFile()
  vpXmlParser::cleanup();

  return 0;
#endif
}
