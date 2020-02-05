#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpColVector.h>

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpRobotViper850 robot;

  // Enable the position control of the robot
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Get the current robot joint positions
  vpColVector q;        // Current joint position
  robot.getPosition(vpRobot::ARTICULAR_FRAME, q);

  // Save this position in a file named "current.pos"
  robot.savePosFile("current.pos", q);

  // Get the position from a file and move to the registered position
  robot.readPosFile("current.pos", q); // Set the joint position from the file

  robot.setPositioningVelocity(5); // Positioning velocity set to 5%
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q); // Move to the joint position
#endif
}
