#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::string filename("matrix.bin");
  bool binary_data = true;
  {
    vpMatrix M(2, 3);
    M[0][0] = -1; M[0][1] = -2; M[0][2] = -3;
    M[1][0] = 4; M[1][1] = 5.5; M[1][2] = 6.0f;

    std::string header("My header");

    if (vpMatrix::saveMatrix(filename, M, binary_data, header.c_str())) {
      std::cout << "Matrix saved in " << filename << std::endl;
      M.print(std::cout, 10, header);
    }
    else {
      std::cout << "Cannot save matrix in " << filename << std::endl;
    }
  }
  {
    vpMatrix N;
    char header[FILENAME_MAX];
    if (vpMatrix::loadMatrix(filename, N, binary_data, header)) {
      std::cout << "Matrix loaded from " << filename << std::endl;
      N.print(std::cout, 10, header);
    }
    else {
      std::cout << "Cannot load matrix from " << filename << std::endl;
    }
  }
}
