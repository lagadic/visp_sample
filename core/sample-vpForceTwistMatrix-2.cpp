#include <visp3/core/vpForceTwistMatrix.h>

int main()
{
  vpForceTwistMatrix aFb, bFc;
  // ... initialize the force/torque twist transformations aFb and bFc
  // Compute the force/torque transformation from frame a to c
  vpForceTwistMatrix aFc = aFb * bFc;
}
