#include <visp3/core/vpColVector.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/robot/vpRobotAfma6.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_AFMA6
  vpColVector q1(6), q2(6);
  vpHomogeneousMatrix fMc;

  vpRobotAfma6 robot;

  // Get the current articular position of the robot
  robot.getPosition(vpRobot::ARTICULAR_FRAME, q1);

  // Compute the pose of the camera in the reference frame using the
  // direct geometric model
  fMc = robot.getForwardKinematics(q1);
  // this is similar to  fMc = robot.get_fMc(q1);
  // or robot.get_fMc(q1, fMc);

  // Compute the inverse geometric model
  int nbsol; // number of solutions (0, 1 or 2) of the inverse geometric model
  // get the nearest solution to the current articular position
  nbsol = robot.getInverseKinematics(fMc, q1, true);

  if (nbsol == 0)
    std::cout << "No solution of the inverse geometric model " << std::endl;
  else if (nbsol >= 1)
    std::cout << "First solution: " << q1 << std::endl;

  if (nbsol == 2) {
    // Compute the other solution of the inverse geometric model
    q2 = q1;
    robot.getInverseKinematics(fMc, q2, false);
    std::cout << "Second solution: " << q2 << std::endl;
  }
#endif
}
