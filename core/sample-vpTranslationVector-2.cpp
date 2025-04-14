#include <visp3/core/vpConfig.h>
#include <visp3/core/vpTranslationVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  {
    vpTranslationVector t;
    t[0] = 0; t[1] = 0.1; t[2] = 0.5;

    std::cout << "t (m):" << std::endl;
    for (unsigned int i = 0; i < t.size(); i++) {
      std::cout << t[i] << std::endl;
    }
  }
  {
#ifdef VISP_HAVE_CXX11
    vpTranslationVector t;
    t = { 0, 0.1, 0.5 };
    std::cout << "t (m):\n" << t << std::endl;
#endif
  }
  {
    vpTranslationVector t;
    t << 0, 0.1, 0.5;
    std::cout << "t (m):\n" << t << std::endl;
  }
}
