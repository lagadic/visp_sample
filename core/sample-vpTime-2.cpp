#include <visp3/core/vpTime.h>

int main()
{
  std::cout << "%Y/%m/%d %H:%M:%S (default): " << vpTime::getDateTime() << std::endl;
  std::cout << "%Y-%m-%d_%H.%M.%S format   : " << vpTime::getDateTime("%Y-%m-%d_%H.%M.%S") << std::endl;
  std::cout << "%F                format   : " << vpTime::getDateTime("%F") << std::endl;
  std::cout << "%X                format   : " << vpTime::getDateTime("%X") << std::endl;

  return 0;
}
