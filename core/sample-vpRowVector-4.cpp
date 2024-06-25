#include <visp3/core/vpRowVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  int var = 0;
  vpMatrix mat(3, 4);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      mat[i][j] = ++var;
  std::cout << "mat: \n" << mat << std::endl;

  vpRowVector row = mat.stackRows();
  std::cout << "row vector: " << row << std::endl;

  vpMatrix remat = row.reshape(3, 4);
  std::cout << "remat: \n" << remat << std::endl;
}
