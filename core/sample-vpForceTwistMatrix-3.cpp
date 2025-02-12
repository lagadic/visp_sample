#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpForceTwistMatrix.h>
#include <visp3/robot/vpRobotViper850.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpRobotViper850 robot;
  vpColVector sH = robot.getForceTorque(); // Get the force/torque measures

  // Set the transformation from sensor frame to the probe frame
  vpHomogeneousMatrix pMs;
  pMs[2][3] = -0.262; // tz only

  // Set the force/torque twist transformation
  vpForceTwistMatrix pFs(pMs); // Twist transformation matrix from probe to sensor frame

  // Compute the resulting force/torque in the probe frame
  vpColVector pH(6); // Force/torque in the probe frame
  pH = pFs * sH;
#endif
}
