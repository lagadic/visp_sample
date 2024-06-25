#include <visp3/robot/vpRobotAfma6.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

#ifdef VISP_HAVE_AFMA6
int main()
{
  vpRobotAfma6 *robot;

  robot = new vpRobotAfma6;

  delete robot;

  robot = new vpRobotAfma6;

  delete robot;

  return 0;
}
#else
int main() { }
#endif
