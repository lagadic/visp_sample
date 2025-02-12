#include <visp3/core/vpConfig.h>
#include <visp3/core/vpForceTwistMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpForceTwistMatrix aFb, bFc;
  // ... initialize the force/torque twist transformations aFb and bFc
  // Compute the force/torque transformation from frame a to c
  vpForceTwistMatrix aFc = aFb * bFc;
}
