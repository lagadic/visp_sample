#include <visp3/robot/vpRobotViper850.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpRobotViper850 robot;

  // Set the extrinsic camera parameters obtained with a perpective
  // projection model including a distorsion parameter
  robot.init(vpViper850::TOOL_MARLIN_F033C_CAMERA,
       vpCameraParameters::perspectiveProjWithDistortion);
#endif
}
