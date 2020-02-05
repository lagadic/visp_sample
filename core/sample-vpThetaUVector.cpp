#include <iostream>
#include <visp3/core/vpMath.h>
#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpThetaUVector.h>

int main()
{
  vpThetaUVector tu;

  // Initialise the theta U rotation vector
  tu[0] = vpMath::rad( 45.f);
  tu[1] = vpMath::rad(-30.f);
  tu[2] = vpMath::rad( 90.f);

  // Construct a rotation matrix from the theta U angles
  vpRotationMatrix R(tu);

  // Extract the theta U angles from a rotation matrix
  tu.buildFrom(R);

  // Print the extracted theta U angles. Values are the same than the
  // one used for initialization
  std::cout << tu;

  // Since the rotation vector is 3 values column vector, the
  // transpose operation produce a row vector.
  vpRowVector tu_t = tu.t();

  // Print the transpose row vector
  std::cout << tu_t << std::endl;
}
