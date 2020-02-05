#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpColVector.h>

int main()
{
  vpColVector p1(3), p2(3);
  vpRotationMatrix R;

  p2 = R * p1;

  return 0;
}
