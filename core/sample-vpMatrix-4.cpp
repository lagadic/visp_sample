#include <iostream>

#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMatrix.h>

int main()
{
  vpMatrix A;
  vpColVector v(3);

  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  A.diag(v);

  std::cout << "A:\n" << A << std::endl;

  // A is now equal to:
  // 1 0 0
  // 0 2 0
  // 0 0 3
}
