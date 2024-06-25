#include <iostream>

#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix A(4, 4); // A is a symmetric matrix
  A[0][0] = 1/1.; A[0][1] = 1/2.; A[0][2] = 1/3.; A[0][3] = 1/4.;
  A[1][0] = 1/2.; A[1][1] = 1/3.; A[1][2] = 1/4.; A[1][3] = 1/5.;
  A[2][0] = 1/3.; A[2][1] = 1/4.; A[2][2] = 1/5.; A[2][3] = 1/6.;
  A[3][0] = 1/4.; A[3][1] = 1/5.; A[3][2] = 1/6.; A[3][3] = 1/7.;
  std::cout << "Initial symmetric matrix: \n" << A << std::endl;

  vpColVector d; // Eigenvalues
  vpMatrix    V; // Eigenvectors

  // Compute the eigenvalues and eigenvectors
  A.eigenValues(d, V);
  std::cout << "Eigen values: \n" << d << std::endl;
  std::cout << "Eigen vectors: \n" << V << std::endl;

  vpMatrix D;
  D.diag(d); // Eigenvalues are on the diagonal

  std::cout << "D: " << D << std::endl;

  // Verification: A * V = V * D
  std::cout << "AV-VD = 0 ? : \n" << (A*V) - (V*D) << std::endl;
}
