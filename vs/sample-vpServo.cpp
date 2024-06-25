#include <visp3/core/vpColVector.h>
#include <visp3/visual_features/vpFeatureThetaU.h>
#include <visp3/visual_features/vpFeatureTranslation.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpMatrix.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Creation of an homogeneous matrix that represent the displacement
  // the camera has to achieve to move from the desired camera frame
  // and the current one
  vpHomogeneousMatrix cdMc;

  // ... cdMc is here the result of a pose estimation

  // Creation of the current visual feature s = (c*_t_c, ThetaU)
  vpFeatureTranslation s_t(vpFeatureTranslation::cdMc);
  vpFeatureThetaU s_tu(vpFeatureThetaU::cdRc);
  // Set the initial values of the current visual feature s = (c*_t_c, ThetaU)
  s_t.build(cdMc);
  s_tu.build(cdMc);

  // Build the desired visual feature s* = (0,0)
  vpFeatureTranslation s_star_t(vpFeatureTranslation::cdMc); // Default initialization to zero
  vpFeatureThetaU s_star_tu(vpFeatureThetaU::cdRc);// Default initialization to zero

  vpColVector v; // Camera velocity
  double error;  // Task error

  // Creation of the visual servo task.
  vpServo task;

  // Visual servo task initialization
  // - Camera is monted on the robot end-effector and velocities are
  //   computed in the camera frame
  task.setServo(vpServo::EYEINHAND_CAMERA);
  // - Interaction matrix is computed with the current visual features s
  task.setInteractionMatrixType(vpServo::CURRENT);
  // - Set the contant gain to 1
  task.setLambda(1);
  // - Add current and desired translation feature
  task.addFeature(s_t, s_star_t);
  // - Add current and desired ThetaU feature for the rotation
  task.addFeature(s_tu, s_star_tu);

  // Visual servoing loop. The objective is here to update the visual
  // features s = (c*_t_c, ThetaU), compute the control law and apply
  // it to the robot
  do {
    // ... cdMc is here the result of a pose estimation

    // Update the current visual feature s
    s_t.build(cdMc);  // Update translation visual feature
    s_tu.build(cdMc); // Update ThetaU visual feature

    v = task.computeControlLaw(); // Compute camera velocity skew
    error = (task.getError()).sumSquare(); // error = ||s - s_star||
  } while (error > 0.0001); // Stop the task when current and desired visual features are close

  // A call to kill() is requested here to destroy properly the current
  // and desired feature lists.
  task.kill();
}
