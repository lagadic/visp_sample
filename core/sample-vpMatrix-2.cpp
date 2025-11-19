#include <iostream>

#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix A(3, 3); // A is a symmetric matrix
  A[0][0] = 1/1.; A[0][1] = 1/2.; A[0][2] = 1/3.;
  A[1][0] = 1/2.; A[1][1] = 1/3.; A[1][2] = 1/4.;
  A[2][0] = 1/3.; A[2][1] = 1/4.; A[2][2] = 1/5.;
  std::cout << "Initial symmetric matrix: \n" << A << std::endl;

  // Compute the eigen values
  vpColVector evalue; // Eigenvalues
  evalue = A.eigenValues();
  std::cout << "Eigen values: \n" << evalue << std::endl;
}
