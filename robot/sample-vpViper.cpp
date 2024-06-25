#include <visp3/robot/vpViper.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpViper robot;
  vpColVector q(6); // The measured six joint positions

  vpHomogeneousMatrix fMe; // Transformation from fix frame to end-effector
  robot.get_fMe(q, fMe); // Get the forward kinematics

  // The forward kinematics can also be computed by considering the wrist frame
  vpHomogeneousMatrix fMw; // Transformation from fix frame to wrist frame
  robot.get_fMw(q, fMw);
  vpHomogeneousMatrix wMe; // Transformation from wrist frame to end-effector
  robot.get_wMe(wMe); // Constant transformation

  // Compute the forward kinematics
  fMe = fMw * wMe;
}
