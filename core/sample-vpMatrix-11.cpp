#include <visp3/core/vpMatrix.h>
#include <visp3/core/vpRowVector.h>

int main()
{
  vpMatrix A(4,4);

  for(unsigned int i=0; i < A.getRows(); i++)
    for(unsigned int j=0; j < A.getCols(); j++)
      A[i][j] = i*A.getCols()+j;

  A.print(std::cout, 4);

  vpRowVector rv1 = A.getRow(1);
  std::cout << "Row vector: \n" << rv1 << std::endl;

  vpRowVector rv2 = A.getRow(1, 1, 3);
  std::cout << "Row vector: \n" << rv2 << std::endl;
}
