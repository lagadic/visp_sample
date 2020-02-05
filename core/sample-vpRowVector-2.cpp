#include <visp3/core/vpRowVector.h>

int main()
{
  vpRowVector A, B(5);
  for (unsigned int i=0; i<B.size(); i++)
    B[i] = i;
  A << B;
  std::cout << "A: \n" << A << std::endl;
}
