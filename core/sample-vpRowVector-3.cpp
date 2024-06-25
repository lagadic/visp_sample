#include <visp3/core/vpRowVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpRowVector v(4);
  int val = 0;
  for (size_t i = 0; i<v.getCols(); i++) {
    v[i] = val++;
  }
  std::cout << "v: " << v << std::endl;

  vpRowVector w;
  w.init(v, 1, 2);
  std::cout << "w: " << w << std::endl;
}
