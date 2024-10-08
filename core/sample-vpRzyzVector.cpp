#include <visp3/core/vpMath.h>
#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpRzyzVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpRzyzVector rzyz;

  // Initialise the Euler angles
  rzyz[0] = vpMath::rad(45.f); // phi   angle in rad/s around z axis
  rzyz[1] = vpMath::rad(-30.f); // theta angle in rad/s around y axis
  rzyz[2] = vpMath::rad(90.f); // psi   angle in rad/s around z axis

  // Construct a rotation matrix from the Euler angles
  vpRotationMatrix R(rzyz);

  // Extract the Euler angles around z,y,z axis from a rotation matrix
  rzyz.buildFrom(R);

  // Print the extracted Euler angles. Values are the same than the
  // one used for initialization
  std::cout << rzyz;

  // Since the rotation vector is 3 values column vector, the
  // transpose operation produce a row vector.
  vpRowVector rzyz_t = rzyz.t();

  // Print the transpose row vector
  std::cout << rzyz_t << std::endl;
}
