#include <visp3/core/vpRowVector.h>

int main()
{
  {
  vpRowVector v(3);
  v[0] = -1; v[1] = -2.1; v[2] = -3;

  std::cout << "v:" << std::endl;
  for (unsigned int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  }

  {
#ifdef VISP_HAVE_CXX11
  vpRowVector v{-1, -2.1, -3};
  std::cout << "v:\n" << v << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
  vpRowVector v;
  v = {-1, -2.1, -3};
#endif
  }
}
