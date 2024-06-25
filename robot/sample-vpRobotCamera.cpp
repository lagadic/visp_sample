#include <visp3/robot/vpRobotCamera.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpHomogeneousMatrix cMw;
  vpRobotCamera robot;

  robot.getPosition(cMw); // Position of the camera in the world frame
  std::cout << "Default position of the camera in the world frame cMw:\n" << cMw << std::endl;

  cMw[2][3] = 1.; // World frame is 1 meter along z axis in front of the camera frame
  robot.setPosition(cMw); // Set the new position of the camera wrt the world frame
  std::cout << "New position of the camera wrt the world frame cMw:\n" << cMw << std::endl;

  robot.setSamplingTime(0.100); // Modify the default sampling time to 0.1 second
  robot.setMaxTranslationVelocity(1.); // vx, vy and vz max set to 1 m/s
  robot.setMaxRotationVelocity(vpMath::rad(90)); // wx, wy and wz max set to 90 deg/s

  vpColVector v(6);
  v = 0;
  v[2] = 1.; // set v_z to 1 m/s
  robot.setVelocity(vpRobot::CAMERA_FRAME, v);
  // The robot has moved from 0.1 meters along the z axis
  robot.getPosition(cMw); // Position of the camera wrt the world frame
  std::cout << "New position of the camera cMw:\n" << cMw << std::endl;
}
