#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpTranslationVector.h>

int main()
{
  vpTranslationVector t; // Translation vector

  // Initialization of the translation vector
  t[0] =  0.2; // tx = 0.2 meters
  t[1] = -0.1; // ty = -0.1 meters
  t[2] =  1.0; // tz = 1 meters

  // Construction of a rotation matrix
  vpRotationMatrix R; // Set to identity by default

  // Construction of an homogeneous matrix
  vpHomogeneousMatrix M(t, R);
}
