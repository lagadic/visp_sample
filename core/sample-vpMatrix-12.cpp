#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpMatrix M(4, 5);
  int val = 0;
  for (size_t i = 0; i<M.getRows(); i++) {
    for (size_t j = 0; j<M.getCols(); j++) {
      M[i][j] = val++;
    }
  }
  M.print(std::cout, 4, "M ");

  vpMatrix N;
  N.init(M, 0, 1, 2, 3);
  N.print(std::cout, 4, "N ");
}
