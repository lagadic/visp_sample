#include <visp3/core/vpColVector.h>
#include <visp3/core/vpMatrix.h>

int main()
{
  vpMatrix A(4,4);

  for(unsigned int i=0; i < A.getRows(); i++)
    for(unsigned int j=0; j < A.getCols(); j++)
      A[i][j] = i*A.getCols()+j;

  A.print(std::cout, 4);

  vpColVector cv1 = A.getCol(1);
  std::cout << "Column vector: \n" << cv1 << std::endl;

  vpColVector cv2 = A.getCol(1, 1, 3);
  std::cout << "Column vector: \n" << cv2 << std::endl;
}
