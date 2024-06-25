#include <visp3/core/vpColVector.h>
#include <visp3/core/vpVelocityTwistMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpVelocityTwistMatrix fVc; // Twist transformation matrix from fix to camera frame

  vpHomogeneousMatrix fMc; // Fix to camera frame transformation
  // ... fMc need here to be initialized

  fVc.build(fMc);

  vpColVector c_v(6); // Velocity in the camera frame: vx,vy,vz,wx,wy,wz
  // ... c_v should here have an initial value


  vpColVector f_v(6); // Velocity in the fix frame: vx,vy,vz,wx,wy,wz

  // Compute the velocity in the fix frame
  f_v = fVc * c_v;

  return 0;
}
