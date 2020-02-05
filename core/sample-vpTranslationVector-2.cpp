#include <visp3/core/vpTranslationVector.h>

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
    t = {0, 0.1, 0.5};
    std::cout << "t (m):\n" << t << std::endl;
#endif
  }
  {
    vpTranslationVector t;
    t << 0, 0.1, 0.5;
    std::cout << "t (m):\n" << t << std::endl;
  }
}
