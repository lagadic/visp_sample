#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  {
    vpColVector v(3);
    v[0] = -1; v[1] = -2.1; v[2] = -3;

    std::cout << "v:" << std::endl;
    for (unsigned int i = 0; i < v.size(); i++) {
      std::cout << v[i] << std::endl;
    }
  }

  {
#ifdef VISP_HAVE_CXX11
    vpColVector v { -1, -2.1, -3 };
    std::cout << "v:\n" << v << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
    vpColVector v;
    v = { -1, -2.1, -3 };
#endif
  }
}
