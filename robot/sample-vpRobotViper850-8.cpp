#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  // Set requested joint velocities
  vpColVector q_dot(6);
  q_dot[0] = 0.1;    // Joint 1 velocity in rad/s
  q_dot[1] = 0.2;    // Joint 2 velocity in rad/s
  q_dot[2] = 0.3;    // Joint 3 velocity in rad/s
  q_dot[3] = M_PI/8; // Joint 4 velocity in rad/s
  q_dot[4] = M_PI/4; // Joint 5 velocity in rad/s
  q_dot[5] = M_PI/16;// Joint 6 velocity in rad/s

  vpRobotViper850 robot;

  robot.setRobotState(vpRobot::STATE_VELOCITY_CONTROL);

  // Moves the joint in velocity
  robot.setVelocity(vpRobot::ARTICULAR_FRAME, q_dot);

  // Initialisation of the velocity measurement
  vpColVector q_dot_mes; // Measured velocities
  robot.getVelocity(vpRobot::ARTICULAR_FRAME, q_dot_mes); // q_dot_mes =0
  // q_dot_mes is resized to 6, the number of joint

  for (; ; ) {
    q_dot_mes = robot.getVelocity(vpRobot::ARTICULAR_FRAME);
    vpTime::wait(40); // wait 40 ms
    // here q_dot_mes is equal to [0.1, 0.2, 0.3, M_PI/8, M_PI/4, M_PI/16]
}
#endif
}
