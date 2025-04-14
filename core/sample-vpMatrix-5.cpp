#include <visp3/core/vpConfig.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix M(3, 2);
  M[0][0] = 1;   M[0][1] = 6;
  M[1][0] = 2;   M[1][1] = 8;
  M[2][0] = 0.5; M[2][1] = 9;

  vpColVector w;
  vpMatrix V, Sigma, U = M;

  U.svd(w, V);

  // Construct the diagonal matrix from the singular values
  Sigma.diag(w);

  // Reconstruct the initial matrix using the decomposition
  vpMatrix Mrec = U * Sigma * V.t();

  // Here, Mrec is obtained equal to the initial value of M
  // Mrec[0][0] = 1;   Mrec[0][1] = 6;
  // Mrec[1][0] = 2;   Mrec[1][1] = 8;
  // Mrec[2][0] = 0.5; Mrec[2][1] = 9;

  std::cout << "Reconstructed M matrix: \n" << Mrec << std::endl;
}
