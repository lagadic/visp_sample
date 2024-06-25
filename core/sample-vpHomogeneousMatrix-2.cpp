#include <visp3/core/vpHomogeneousMatrix.h>

int main()
{
  std::vector<double> v(12, 0);
  v[1] = -1.; // ry=-90
  v[4] = 1.; // rx=90
  v[10] = -1.; // rz=-90
  v[3] = 0.3; // tx
  v[7] = 0.4; // ty
  v[11] = 0.5; // tz

  std::cout << "v: ";
  for (unsigned int i = 0; i<v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;

  vpHomogeneousMatrix M1(v);
  std::cout << "M1:\n" << M1 << std::endl;

  vpHomogeneousMatrix M2;
  M2.build(v);
  std::cout << "M2:\n" << M2 << std::endl;
}
