#include <visp3/core/vpMatrix.h>

int main()
{
  vpMatrix M(4,5);
  int val = 0;
  for(size_t i=0; i<M.getRows(); i++) {
    for(size_t j=0; j<M.getCols(); j++) {
      M[i][j] = val++;
    }
  }
  M.print (std::cout, 4, "M ");
  vpMatrix N = M.extract(0, 1, 2, 3);
  N.print (std::cout, 4, "N ");
}
