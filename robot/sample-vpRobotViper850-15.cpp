#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpTime.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpColVector  H; // force/torque measures [Fx, Fy, Fz, Tx, Ty, Tz]

  vpRobotViper850 robot;

  // Bias the force/torque sensor
  robot.biasForceTorqueSensor();

  for (int i = 0; i< 10; i++) {
    robot.getForceTorque(H);
    std::cout << "Measured force/torque: " << H.t() << std::endl;
    vpTime::wait(5);
  }
#endif
}
