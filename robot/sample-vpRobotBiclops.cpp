#include <visp3/robot/vpRobotBiclops.h>

int main()
{
#ifdef VISP_HAVE_BICLOPS
  vpRobotBiclops robot; // Use the default config file in /usr/share/BiclopsDefault.cfg"

  // Specify the config file location
  robot.setConfigFile("/usr/share/BiclopsDefault.cfg"); // Not mandatory since the file is the default one

  // Initialize the head
  robot.init();

  // Move the robot to a specified pan and tilt
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL) ;
  vpColVector q(2);
  q[0] = vpMath::rad(20); // pan
  q[1] = vpMath::rad(40); // tilt
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);
#endif
  return 0;
}
