#include <iostream>
#include <vector>
#include <visp3/core/vpImagePoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::vector<vpImagePoint> ip(2);

  ip[0].set_ij(100, 200);
  ip[1].set_ij(300, 400);

  vpImagePoint cog(0, 0);
  for (unsigned int i = 0; i<ip.size(); i++)
    cog += ip[i];
  cog /= ip.size();
  std::cout << "cog: " << cog << std::endl;
}
