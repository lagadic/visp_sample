#include <visp3/core/vpImage.h>
#include <visp3/robot/vpWireFrameSimulator.h>

int main()
{
  vpWireFrameSimulator sim;

  vpImage<vpRGBa> Iint(480, 640, vpRGBa(255));
  vpImage<vpRGBa> Iext(480, 640, vpRGBa(255));

  //Set the type of scene to use
  sim.initScene(vpWireFrameSimulator::PLATE, vpWireFrameSimulator::D_STANDARD);

  //Set the initial pose of the camera
  sim.setCameraPositionRelObj(vpHomogeneousMatrix(0, 0, 0.5, vpMath::rad(0), vpMath::rad(10), 0));
  //Set the desired pose of the camera (for the internal view)
  sim.setDesiredCameraPosition(vpHomogeneousMatrix(0.0, 0, 0.5, 0, 0, 0));
  //Set the pose of the reference frame (for the external view)
  sim.setExternalCameraPosition(vpHomogeneousMatrix(0.1, 0, 0.2, 0, 0, 0));

  //Set the camera parameters
  vpCameraParameters camera(1000, 1000, 320, 240);
  sim.setInternalCameraParameters(camera);
  sim.setExternalCameraParameters(camera);

  //Get the internal view
  sim.getInternalImage(Iint);

  //Get the external view
  sim.getExternalImage(Iext);

  return 0;
}
