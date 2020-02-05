#include <visp3/robot/vpSimulatorPioneer.h>

int main()
{
  vpHomogeneousMatrix wMc;
  vpSimulatorPioneer robot;

  robot.getPosition(wMc); // Position of the camera in the world frame
  std::cout << "Default position of the camera in the world frame wMc:\n" << wMc << std::endl;

  robot.setSamplingTime(0.100); // Modify the default sampling time to 0.1 second
  robot.setMaxTranslationVelocity(1.); // vx max set to 1 m/s
  robot.setMaxRotationVelocity(vpMath::rad(90)); // wz max set to 90 deg/s

  vpColVector v(2); // we control vx and wz dof
  v = 0;
  v[0] = 1.; // set vx to 1 m/s
  robot.setVelocity(vpRobot::ARTICULAR_FRAME, v);
  // The robot has moved from 0.1 meters along the z axis
  robot.getPosition(wMc); // Position of the camera in the world frame
  std::cout << "New position of the camera wMc:\n" << wMc << std::endl;
}
