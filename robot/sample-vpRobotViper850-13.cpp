#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpColVector.h>

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpColVector q;
  vpRobotViper850 robot;

  robot.readPosFile("MyPositionFilename.pos", q);
  robot.setRobotState(vpRobot::STATE_POSITION_CONTROL);
  robot.setPosition(vpRobot::ARTICULAR_FRAME, q);
#endif
}
