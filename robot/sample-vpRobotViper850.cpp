#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotViper850.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpRobotViper850 robot;
#endif
}
