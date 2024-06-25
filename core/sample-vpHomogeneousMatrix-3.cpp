#include <visp3/core/vpHomogeneousMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  {
    vpHomogeneousMatrix M;
    M[0][0] = 0; M[0][1] = 0; M[0][2] = -1; M[0][3] = 0.1;
    M[1][0] = 0; M[1][1] = -1; M[1][2] = 0; M[1][3] = 0.2;
    M[2][0] = -1; M[2][1] = 0; M[2][2] = 0; M[2][3] = 0.3;

    std::cout << "M:" << std::endl;
    for (unsigned int i = 0; i < M.getRows(); i++) {
      for (unsigned int j = 0; j < M.getCols(); j++) {
        std::cout << M[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  {
    vpTranslationVector t(0.1, 0.2, 0.3);
    vpRxyzVector rxyz(0, -M_PI_2, M_PI);
    vpRotationMatrix R(rxyz);
    vpHomogeneousMatrix M(t, R);
    std::cout << "M:\n" << M << std::endl;
  }

  {
    vpTranslationVector t;
    vpRotationMatrix R;
    R << 0, 0, -1,
      0, -1, 0,
      -1, 0, 0;
    t << 0.1, 0.2, 0.3;
    vpHomogeneousMatrix M(t, R);
    std::cout << "M:\n" << M << std::endl;
  }
  {
#ifdef VISP_HAVE_CXX11
    vpHomogeneousMatrix M(vpTranslationVector(0.1, 0.2, 0.3), vpRotationMatrix({ 0, 0, -1, 0, -1, 0, -1, 0, 0 }));
    std::cout << "M:\n" << M << std::endl;
#endif
  }

}
