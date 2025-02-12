#include <visp3/core/vpConfig.h>
#include <visp3/core/vpRowVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpRowVector v(4);
  for (unsigned int i = 0; i < v.size(); i++)
    v[i] = i;
  std::cout << "v: " << v << std::endl;

  vpRowVector w(2);
  for (unsigned int i = 0; i < w.size(); i++)
    w[i] = i+10;
  std::cout << "w: " << w << std::endl;

  v.insert(1, w);
  std::cout << "v: " << v << std::endl;
}
