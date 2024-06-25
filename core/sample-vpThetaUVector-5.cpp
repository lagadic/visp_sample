#include <visp3/core/vpThetaUVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  {
    vpThetaUVector tu;
    tu[0] = M_PI; tu[1] = M_PI_2; tu[2] = M_PI_4;

    std::cout << "tu (rad):" << std::endl;
    for (unsigned int i = 0; i < tu.size(); i++) {
      std::cout << tu[i] << std::endl;
    }
  }
  {
#ifdef VISP_HAVE_CXX11
    vpThetaUVector tu;
    tu = { M_PI, M_PI_2, M_PI_4 };
    std::cout << "tu (rad):\n" << tu << std::endl;
#endif
  }
  {
    vpThetaUVector tu;
    tu << M_PI, M_PI_2, M_PI_4;
    std::cout << "tu (rad):\n" << tu << std::endl;
  }
}
