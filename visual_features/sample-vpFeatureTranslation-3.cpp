#include <visp3/visual_features/vpFeatureTranslation.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/vs/vpServo.h>

int main()
{
  vpServo task; // Visual servoing task

  vpHomogeneousMatrix cdMo;
  // ... cdMo need here to be initialized from for example a pose estimation.

  // Creation of the desired visual feature s*
  vpFeatureTranslation s_star(vpFeatureTranslation::cMo);
  s_star.buildFrom(cdMo); // Initialization of the desired feature s*=(tx*,ty*,tz*)

  vpHomogeneousMatrix cMo;
  // ... cMo need here to be computed.

  // Creation of the current visual feature s
  vpFeatureTranslation s(vpFeatureTranslation::cMo);
  s.buildFrom(cMo); // Initialization of the current feature s=(tx,ty,tz)

  // Set eye-in-hand control law. 
  // The computed velocities will be expressed in the camera frame
  task.setServo(vpServo::EYEINHAND_CAMERA);
  // Interaction matrix is computed with the current visual features s
  task.setInteractionMatrixType(vpServo::CURRENT); 
  // Set the constant gain
  double lambda = 0.8;
  task.setLambda(lambda);  

  // Add the 3D translation feature to the task
  task.addFeature(s, s_star); // s* is here considered as zero

  // Control loop
  for ( ; ; ) {
    // ... cMo need here to be computed from for example a pose estimation.
    
    // Update the current 3D translation visual feature
    s.buildFrom(cMo);
    
    // compute the control law
    vpColVector v = task.computeControlLaw(); // camera velocity
  }
}
