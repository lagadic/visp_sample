#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if 0
  vpMatrix A(5, 4);

  A[0][0] = 1/1.; A[0][1] = 1/2.; A[0][2] = 1/3.; A[0][3] = 1/4.;
  A[1][0] = 1/5.; A[1][1] = 1/3.; A[1][2] = 1/3.; A[1][3] = 1/5.;
  A[2][0] = 1/6.; A[2][1] = 1/4.; A[2][2] = 1/2.; A[2][3] = 1/6.;
  A[3][0] = 1/7.; A[3][1] = 1/5.; A[3][2] = 1/6.; A[3][3] = 1/7.;
  A[4][0] = 1/8.; A[4][1] = 1/6.; A[4][2] = 1/7.; A[4][3] = 1/8.;
#else
  vpMatrix A(2, 3);

  A[0][0] = 2; A[0][1] = 3; A[0][2] = 5;
  A[1][0] = -4; A[1][1] = 2; A[1][2] = 3;
#endif
  A.print(std::cout, 10, "A: ");

  vpMatrix A_p;
  unsigned int rank = A.pseudoInverse(A_p);

  A_p.print(std::cout, 10, "A^+ (pseudo-inverse): ");
  std::cout << "Rank: " << rank << std::endl;
}
