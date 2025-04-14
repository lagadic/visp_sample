#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpColVector position(6);
  position = 0; // position in rad

  vpRobotViper850 robot;

  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Set the max velocity to 20%
  robot.setPositioningVelocity(20);

  // Moves the robot to the joint position [0,0,0,0,0,0]
  robot.setPosition(vpRobot::ARTICULAR_FRAME, position);
#endif
}
