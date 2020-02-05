#include <visp3/visual_features/vpFeatureThetaU.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/vs/vpServo.h>

int main()
{
  vpServo task; // Visual servoing task

  vpHomogeneousMatrix cMcd;
  // ... cMcd need here to be initialized from for example a pose estimation.

  // Creation of the current feature s that correspond to the rotation
  // in angle/axis parametrization between the current camera frame
  // and the desired camera frame
  vpFeatureThetaU s(vpFeatureThetaU::cRcd);
  s.buildFrom(cMcd); // Initialization of the feature

  // Set eye-in-hand control law. 
  // The computed velocities will be expressed in the camera frame
  task.setServo(vpServo::EYEINHAND_CAMERA);
  // Interaction matrix is computed with the current visual features s
  task.setInteractionMatrixType(vpServo::CURRENT); 

  // Add the 3D ThetaU feature to the task
  task.addFeature(s); // s* is here considered as zero
  // Add the (ThetaU_x, ThetaU_y) subset feature from the 3D ThetaU
  // rotation to the task
  // task.addFeature(s, 
  //		  vpFeatureThetaU::selectTUx() 
  //		  | vpFeatureThetaU::selectTUy());

  // Control loop
  for ( ; ; ) {
    // ... cMcd need here to be initialized from for example a pose estimation.
    
    // Update the current ThetaU visual feature
    s.buildFrom(cMcd);
    
    // compute the control law
    vpColVector v = task.computeControlLaw(); // camera velocity
  }
}
