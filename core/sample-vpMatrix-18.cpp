#include <visp3/core/vpConfig.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  {
    vpMatrix M(2, 3);
    M[0][0] = -1; M[0][1] = -2; M[0][2] = -3;
    M[1][0] = 4; M[1][1] = 5.5; M[1][2] = 6.0f;

    std::cout << "M:" << std::endl;
    for (unsigned int i = 0; i < M.getRows(); i++) {
      for (unsigned int j = 0; j < M.getCols(); j++) {
        std::cout << M[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  {
#ifdef VISP_HAVE_CXX11
    vpMatrix M({ {-1, -2, -3}, {4, 5.5, 6} });
    //vpMatrix M{ {-1, -2, -3}, {4, 5.5, 6.0f} };
    std::cout << "M:\n" << M << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
    vpMatrix M(2, 3, { -1, -2, -3, 4, 5.5, 6.0f });
    std::cout << "M:\n" << M << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
    vpMatrix M({ -1, -2, -3, 4, 5.5, 6.0f });
    M.reshape(2, 3);
    std::cout << "M:\n" << M << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
    vpMatrix M;
    M = { {-1, -2, -3}, {4, 5.5, 6.0f} };
    std::cout << "M:\n" << M << std::endl;
#endif
  }
}
