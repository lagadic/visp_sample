#include <visp3/robot/vpSimulatorViper850.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMath.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_MODULE_GUI) && defined(VISP_HAVE_THREADS)
  vpSimulatorViper850 robot;

  vpColVector q(6);
  // Set q[i] with i in [0:5]

  // Initialize the controller to position control
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Set the max velocity to 40%
  robot.setPositioningVelocity(40);

  // Moves the robot in the joint space
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);
#endif
  return 0;
}
