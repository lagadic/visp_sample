#include <visp3/robot/vpSimulatorViper850.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMath.h>

int main()
{
  vpSimulatorViper850 robot;

  vpColVector q(6);
  // Set q[i] with i in [0:5]

  // Initialize the controller to position control
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Set the max velocity to 40%
  robot.setPositioningVelocity(40);

  // Moves the robot in the joint space
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);

  return 0;
}
