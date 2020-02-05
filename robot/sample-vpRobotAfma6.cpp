#include <visp3/robot/vpRobotAfma6.h>

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
int main() {}
#endif
