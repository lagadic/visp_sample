#include <visp3/core/vpColVector.h>

int main()
{
  int var=0;
  vpMatrix mat(3, 4);
  for (int i = 0; i < 3; i++)
      for (int j = 0; j < 4; j++)
          mat[i][j] = ++var;
  std::cout << "mat: \n" << mat << std::endl;

  vpColVector col = mat.stackColumns();
  std::cout << "column vector: \n" << col << std::endl;

  vpMatrix remat = col.reshape(3, 4);
  std::cout << "remat: \n" << remat << std::endl;
}
