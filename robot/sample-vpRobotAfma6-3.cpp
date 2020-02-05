#include <visp3/robot/vpRobotAfma6.h>
#include <visp3/core/vpColVector.h>
#include <visp3/robot/vpRobotException.h>

int main()
{
#ifdef VISP_HAVE_AFMA6
  vpColVector position(6);
  // Set positions in the camera frame
  position[0] = 0.1;    // x axis, in meter
  position[1] = 0.2;    // y axis, in meter
  position[2] = 0.3;    // z axis, in meter
  position[3] = M_PI/8; // rotation around x axis, in rad
  position[4] = M_PI/4; // rotation around y axis, in rad
  position[5] = M_PI/10;// rotation around z axis, in rad

  vpRobotAfma6 robot;

  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Set the max velocity to 20%
  robot.setPositioningVelocity(20);

  // Moves the robot in the camera frame
  //robot.setPosition(vpRobot::CAMERA_FRAME, position);
  try {
    robot.setPosition(vpRobot::CAMERA_FRAME, position);
  }
  catch (vpRobotException e) {
    if (e.getCode() == vpRobotException::positionOutOfRangeError) {
      std::cout << "The position is out of range" << std::endl;
    }
  }

  return 0;
#endif
}
