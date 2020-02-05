#include <visp3/core/vpMath.h>
#include <visp3/core/vpThetaUVector.h>

int main()
{
  vpThetaUVector tu;

  // Initialise the theta U rotation vector
  tu = vpMath::rad( 45.f); // All the 3 angles are set to 45 degrees
}
