#include <visp3/core/vpMath.h>
#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpRzyxVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpRzyxVector rzyx;

  // Initialise the Euler angles
  rzyx[0] = vpMath::rad(45.f); // phi   angle in rad/s around z axis
  rzyx[1] = vpMath::rad(-30.f); // theta angle in rad/s around y axis
  rzyx[2] = vpMath::rad(90.f); // psi   angle in rad/s around x axis

  // Construct a rotation matrix from the Euler angles
  vpRotationMatrix R(rzyx);

  // Extract the Euler angles around z,y,x axis from a rotation matrix
  rzyx.buildFrom(R);

  // Print the extracted Euler angles. Values are the same than the
  // one used for initialization
  std::cout << rzyx;

  // Since the rotation vector is 3 values column vector, the
  // transpose operation produce a row vector.
  vpRowVector rzyx_t = rzyx.t();

  // Print the transpose row vector
  std::cout << rzyx_t << std::endl;
}
