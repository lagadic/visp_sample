#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpRobotViper850.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpTranslationVector.h>
#include <visp3/core/vpRxyzVector.h>
#include <visp3/core/vpRotationMatrix.h>
#include <visp3/core/vpHomogeneousMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_VIPER850
  vpRobotViper850 robot;
  double timestamp;

  vpColVector position;
  robot.getPosition(vpRobot::REFERENCE_FRAME, position, timestamp);

  vpTranslationVector ftc; // reference frame to camera frame translations
  vpRxyzVector frc; // reference frame to camera frame rotations

  // Update the transformation between reference frame and camera frame
  for (int i = 0; i < 3; i++) {
    ftc[i] = position[i];   // tx, ty, tz
    frc[i] = position[i+3]; // ry, ry, rz
  }

  // Create a rotation matrix from the Rxyz rotation angles
  vpRotationMatrix fRc(frc); // reference frame to camera frame rotation matrix

  // Create the camera to fix frame transformation in terms of a
  // homogenous matrix
  vpHomogeneousMatrix fMc(ftc, fRc);
#endif
}
