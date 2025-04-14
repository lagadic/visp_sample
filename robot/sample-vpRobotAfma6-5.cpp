#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotAfma6.h>
#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_AFMA6
  vpRobotAfma6 robot;
  vpColVector q; // joint position

  robot.readPosFile("MyPositionFilename.pos", q);
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);

  return 0;
#endif
}
