#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotAfma6.h>
#include <visp3/core/vpPoseVector.h>
#include <visp3/robot/vpRobotException.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_AFMA6
  vpPoseVector pose;
  // Set positions in the reference frame
  pose[0] = 0.1;    // x axis, in meter
  pose[1] = 0.;     // y axis, in meter
  pose[2] = 0.3;    // z axis, in meter
  pose[3] = M_PI/8; // ThetaU rotation around x axis, in rad
  pose[4] = M_PI/4; // ThetaU rotation around y axis, in rad
  pose[5] = 0;      // ThetaU rotation around z axis, in rad

  vpRobotAfma6 robot;

  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Set the max velocity to 20%
  robot.setPositioningVelocity(20);

  // Moves the robot in the camera frame
  //  robot.setPosition(vpRobot::REFERENCE_FRAME, pose);
  try {
    robot.setPosition(vpRobot::REFERENCE_FRAME, pose);
  }
  catch (vpRobotException e) {
    if (e.getCode() == vpRobotException::positionOutOfRangeError) {
      std::cout << "The position is out of range" << std::endl;
    }
  }

  return 0;
#endif
}
