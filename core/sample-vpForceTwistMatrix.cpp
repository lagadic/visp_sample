#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpForceTwistMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpForceTwistMatrix sFp; // Twist transformation matrix from sensor to probe frame

  vpHomogeneousMatrix sMp; // Force/torque sensor frame to probe frame transformation
  // ... sMp need here to be initialized

  sFp.buildFrom(sMp);

  vpColVector p_H(6); // Force/torque skew in the probe frame: fx,fy,fz,tx,ty,tz
  // ... p_H should here have an initial value

  vpColVector s_H(6); // Force/torque skew in the sensor frame: fx,fy,fz,tx,ty,tz

  // Compute the value of the force/torque in the sensor frame
  s_H = sFp * p_H;
}
