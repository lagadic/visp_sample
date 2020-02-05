#include <visp3/core/vpColVector.h>

int main()
{
  vpColVector v(10);
  v[0] = 5; v[1] = 7; v[2] = 4; v[3] = 2; v[4] = 8;
  v[5] = 6; v[6] = 1; v[7] = 9; v[8] = 0; v[9] = 3;

  std::cout << "v: " << v.t() << std::endl;

  //  vpColVector s = vpColVector::sort(v);

  vpColVector s = vpColVector::invSort(v);
  std::cout << "s: " << s.t() << std::endl;
}
