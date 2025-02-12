#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix A(3, 3);

  A[0][0] = 4.64;
  A[0][1] = 0.288;
  A[0][2] = -0.384;

  A[1][0] = 0.288;
  A[1][1] = 7.3296;
  A[1][2] = 2.2272;

  A[2][0] = -0.384;
  A[2][1] = 2.2272;
  A[2][2] = 6.0304;

  vpColVector X(3), B(3);
  B[0] = 1;
  B[1] = 2;
  B[2] = 3;

  X = A.solveBySVD(B);
  // Obtained values of X
  // X[0] = 0.2468;
  // X[1] = 0.120782;
  // X[2] = 0.468587;

  std::cout << "X:\n" << X << std::endl;
}
