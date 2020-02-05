#include <visp3/robot/vpSimulatorCamera.h>

int main()
{
  vpHomogeneousMatrix wMc;
  vpSimulatorCamera robot;

  robot.getPosition(wMc); // Position of the camera in the world frame
  std::cout << "Default position of the camera in the world frame wMc:\n" << wMc << std::endl;

  wMc[2][3] = 1.; // Camera frame is 1 meter along z axis in front of the world frame
  robot.setPosition(wMc); // Set the new position of the camera in the world frame
  std::cout << "New position of the camera in the world frame wMc:\n" << wMc << std::endl;

  robot.setSamplingTime(0.100); // Modify the default sampling time to 0.1 second
  robot.setMaxTranslationVelocity(1.); // vx, vy and vz max set to 1 m/s
  robot.setMaxRotationVelocity(vpMath::rad(90)); // wx, wy and wz max set to 90 deg/s

  vpColVector v(6);
  v = 0;
  v[2] = 1.; // set v_z to 1 m/s
  robot.setVelocity(vpRobot::CAMERA_FRAME, v);
  // The robot has moved from 0.1 meters along the z axis
  robot.getPosition(wMc); // Position of the camera in the world frame
  std::cout << "New position of the camera wMc:\n" << wMc << std::endl;
}
