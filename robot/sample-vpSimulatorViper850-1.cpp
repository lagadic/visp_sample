#include <visp3/robot/vpSimulatorViper850.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMath.h>

int main()
{
#if defined(VISP_HAVE_MODULE_GUI) && defined(VISP_HAVE_THREADS)
  vpSimulatorViper850 robot;

  vpColVector q(6);
  // Set a joint position
  q[0] = vpMath::rad(10); // Joint 1 position, in rad
  q[1] = 0.2;             // Joint 2 position, in rad
  q[2] = 0.3;             // Joint 3 position, in rad
  q[3] = M_PI / 8;          // Joint 4 position, in rad
  q[4] = M_PI / 4;          // Joint 5 position, in rad
  q[5] = M_PI;            // Joint 6 position, in rad

  // Initialize the controller to position control
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);

  // Moves the robot in the joint space
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);
#endif
  return 0;
}
