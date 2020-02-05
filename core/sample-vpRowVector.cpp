#include <visp3/core/vpRowVector.h>

int main()
{
  vpRowVector v(4);
  for (unsigned int i=0; i < v.size(); i++)
    v[i] = i;
  std::cout << "v: " << v << std::endl;

  vpRowVector w(2);
  for (unsigned int i=0; i < w.size(); i++)
    w[i] = i+10;
  std::cout << "w: " << w << std::endl;

  v.insert(1, w);
  std::cout << "v: " << v << std::endl;
}
