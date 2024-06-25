#include <iostream>
#include <visp3/core/vpMath.h>
#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpRxyzVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpRxyzVector rxyz;

  // Initialise the Euler angles
  rxyz[0] = vpMath::rad(45.f); // phi   angle in rad around x axis
  rxyz[1] = vpMath::rad(-30.f); // theta angle in rad around y axis
  rxyz[2] = vpMath::rad(90.f); // psi   angle in rad around z axis

  // Construct a rotation matrix from the Euler angles
  vpRotationMatrix R(rxyz);

  // Extract the Euler angles around x,y,z axis from a rotation matrix
  rxyz.build(R);

  // Print the extracted Euler angles. Values are the same than the
  // one used for initialization
  std::cout << rxyz;

  // Since the rotation vector is 3 values column vector, the
  // transpose operation produce a row vector.
  vpRowVector rxyz_t = rxyz.t();

  // Print the transpose row vector
  std::cout << rxyz_t << std::endl;
}
