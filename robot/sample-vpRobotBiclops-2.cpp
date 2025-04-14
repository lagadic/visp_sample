#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotBiclops.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_BICLOPS
  // Specify the config file location and initialize the turret
  vpRobotBiclops robot("/usr/share/BiclopsDefault.cfg");

  // Move the robot to a specified pan and tilt
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  vpColVector q(2);
  q[0] = vpMath::rad(-20); // pan
  q[1] = vpMath::rad(10); // tilt
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);
#endif
  return 0;
}
