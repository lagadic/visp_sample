#include <visp3/core/vpConfig.h>
#include <visp3/core/vpTime.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::cout << "%Y/%m/%d %H:%M:%S (default): " << vpTime::getDateTime() << std::endl;
  std::cout << "%Y-%m-%d_%H.%M.%S format   : " << vpTime::getDateTime("%Y-%m-%d_%H.%M.%S") << std::endl;
  std::cout << "%F                format   : " << vpTime::getDateTime("%F") << std::endl;
  std::cout << "%X                format   : " << vpTime::getDateTime("%X") << std::endl;

  return 0;
}
