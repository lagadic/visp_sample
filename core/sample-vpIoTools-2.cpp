#include <iostream>
#include <string>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpIoTools.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::string envvalue;
  try {
    std::string env = "HOME";
    envvalue = vpIoTools::getenv(env);
    std::cout << "$HOME = \"" << envvalue << "\"" << std::endl;

    envvalue = vpIoTools::getenv("LOGNAME");
    std::cout << "$LOGNAME = \"" << envvalue << "\"" << std::endl;

    envvalue = vpIoTools::getenv("PATH");
    std::cout << "$PATH = \"" << envvalue << "\"" << std::endl;
  }
  catch (...) {
    std::cout << "Cannot get the environment variable value" << std::endl;
    return -1;
  }
  return 0;
}
