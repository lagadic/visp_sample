#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotAfma6.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpVelocityTwistMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpColVector q_vel(6); // Joint velocity on the 6 joints
  // ... q_vel need here to be initialized

  vpColVector c_v(6); // Velocity in the camera frame: vx,vy,vz,wx,wy,wz

  vpVelocityTwistMatrix cVe;  // Velocity skew transformation from camera frame to end-effector
  vpMatrix eJe;       // Robot jacobian

#ifdef VISP_HAVE_AFMA6
  vpRobotAfma6 robot;
  robot.get_cVe(cVe);
  robot.get_eJe(eJe);
#endif

  // Compute the velocity in the camera frame
  c_v = cVe * eJe * q_vel;

  return 0;
}
