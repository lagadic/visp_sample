#include <visp3/core/vpConfig.h>
#include <visp3/core/vpRotationMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  {
    vpRotationMatrix R;
    R[0][0] = 0; R[0][1] = 0; R[0][2] = -1;
    R[1][0] = 0; R[1][1] = -1; R[1][2] = 0;
    R[2][0] = -1; R[2][1] = 0; R[2][2] = 0;

    std::cout << "R:" << std::endl;
    for (unsigned int i = 0; i < R.getRows(); i++) {
      for (unsigned int j = 0; j < R.getCols(); j++) {
        std::cout << R[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  {
#ifdef VISP_HAVE_CXX11
    vpRotationMatrix R { 0, 0, -1, 0, -1, 0, -1, 0, 0 };
    std::cout << "R:\n" << R << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
    vpRotationMatrix R;
    R = { 0, 0, -1, 0, -1, 0, -1, 0, 0 };
    std::cout << "R:\n" << R << std::endl;
#endif
  }

  {
    vpRotationMatrix R;
    R << 0, 0, -1, 0, -1, 0, -1, 0, 0;
    std::cout << "R:\n" << R << std::endl;
  }
}
