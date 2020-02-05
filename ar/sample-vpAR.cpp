#include <visp3/ar/vpAR.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpImage.h>

#ifdef VISP_HAVE_COIN3D_AND_GUI
static void *mainloopfunction(void *_simu)
{
  vpAR *simu = (vpAR *)_simu ;
  simu->initMainApplication() ;

  vpImage<unsigned char> I;
  vpHomogeneousMatrix cMo;

  //Your code to compute the pose cMo.

  //Set the image to use as background.
  simu->setImage(I) ;
  //Set the camera position thanks to the pose cMo computed before.
  simu->setCameraPosition(cMo) ;

  simu->closeMainApplication();
}
#endif

int main()
{
#ifdef VISP_HAVE_COIN3D_AND_GUI
  vpAR simu;
  //Camera parameters.
  vpCameraParameters cam(600,600,160,120);

  //Initialize the internal view of the simulator.
  simu.initInternalViewer(640,480, vpSimulator::grayImage);

  vpTime::wait(300);

  // Load the cad model. 4points.iv can be downloaded on the website
  // with the image package
  simu.load("./4points.iv");

  //Initialize the internal camera parameters.
  simu.setInternalCameraParameters(cam);

  simu.initApplication(&mainloopfunction);

  simu.mainLoop();
#endif
  return 0;
}
