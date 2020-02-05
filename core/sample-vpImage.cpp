#include <visp3/core/vpImage.h>

int main()
{
  vpImage<unsigned char> A(288, 384);
  vpImage<unsigned char> B(288, 384);
  vpImage<unsigned char> C;

  A = 128;
  B = 120;

  // operator-() : C = A - B
  C = A - B;

  // sub() : C = A - B
  //A.sub(B, C); // C = A - B

  return 0;
}
