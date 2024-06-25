#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpColVector v(4);
  for (unsigned int i = 0; i < v.size(); i++)
    v[i] = i;
  std::cout << "v:\n" << v << std::endl;

  vpColVector w(2);
  for (unsigned int i = 0; i < w.size(); i++)
    w[i] = i+10;
  std::cout << "w:\n" << w << std::endl;

  v.insert(1, w);
  std::cout << "v:\n" << v << std::endl;
}
