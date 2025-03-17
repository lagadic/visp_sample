#include <visp3/core/vpIoTools.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::string str_1 = vpIoTools::formatString("/tmp/test-%d.txt", 12);
  std::string str_2 = vpIoTools::formatString("/tmp/test-%04d.txt", 12);
  std::string str_3 = vpIoTools::formatString("test-%05d.txt", 123);

  std::cout << str_1 << std::endl;
  std::cout << str_2 << std::endl;
  std::cout << str_3 << std::endl;
}
