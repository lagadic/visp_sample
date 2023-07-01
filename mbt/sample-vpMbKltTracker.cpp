#include <visp3/mbt/vpMbKltTracker.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpException.h>
#include <visp3/gui/vpDisplayX.h>

int main()
{
#if defined(VISP_HAVE_MODULE_KLT) && (defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION >= 0x020100))
  vpMbKltTracker tracker; // Create a model based tracker via KLT points.
  vpImage<unsigned char> I;
  vpHomogeneousMatrix cMo; // Pose computed using the tracker.
  vpCameraParameters cam;

  // Acquire an image
  vpImageIo::readPGM(I, "cube.pgm");

#if defined VISP_HAVE_X11
  vpDisplayX display;
  display.init(I,100,100,"Mb Klt Tracker");
#endif

  tracker.loadConfigFile("cube.xml"); // Load the configuration of the tracker
  tracker.getCameraParameters(cam);   // Get the camera parameters used by the tracker (from the configuration file).
  tracker.loadModel("cube.cao");      // Load the 3d model in cao format. No 3rd party library is required
  tracker.initClick(I, "cube.init");  // Initialise manually the pose by clicking on the image points associated to the 3d points containned in the cube.init file.

  while(true){
    // Acquire a new image
    vpDisplay::display(I);
    tracker.track(I);     // Track the object on this image
    tracker.getPose(cMo); // Get the pose

    tracker.display(I, cMo, cam, vpColor::darkRed, 1); // Display the model at the computed pose.
    vpDisplay::flush(I);
  }

  return 0;
#endif
}
