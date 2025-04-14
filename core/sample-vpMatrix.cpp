#include <iostream>

#include <visp3/core/vpConfig.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix A(3, 3);
  A[0][0] = 1/1.; A[0][1] = 1/2.; A[0][2] = 1/3.;
  A[1][0] = 1/3.; A[1][1] = 1/4.; A[1][2] = 1/5.;
  A[2][0] = 1/6.; A[2][1] = 1/7.; A[2][2] = 1/8.;
  std::cout << "Initial matrix: \n" << A << std::endl;

  // Compute the determinant
  std::cout << "By defaukt determinant by LU decomposition    : " <<
    A.det() << std::endl;
  std::cout << "Determinant by LU decomposition    : " <<
    A.det(vpMatrix::LU_DECOMPOSITION) << std::endl;
}
