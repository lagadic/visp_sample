#include <visp3/robot/vpSimulatorPioneerPan.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpHomogeneousMatrix wMc;
  vpSimulatorPioneerPan robot;

  robot.getPosition(wMc); // Position of the camera in the world frame
  std::cout << "Default position of the camera in the world frame wMc:\n" << wMc << std::endl;

  robot.setSamplingTime(0.100); // Modify the default sampling time to 0.1 second
  robot.setMaxTranslationVelocity(1.); // vx max set to 1 m/s
  robot.setMaxRotationVelocity(vpMath::rad(90)); // wz max set to 90 deg/s

  vpColVector v(3); // we control vx, wz and q_pan
  v = 0;
  v[0] = 1.; // set vx to 1 m/s
  robot.setVelocity(vpRobot::ARTICULAR_FRAME, v);
  // The robot has moved from 0.1 meters along the z axis
  robot.getPosition(wMc); // Position of the camera in the world frame
  std::cout << "New position of the camera wMc:\n" << wMc << std::endl;
}
