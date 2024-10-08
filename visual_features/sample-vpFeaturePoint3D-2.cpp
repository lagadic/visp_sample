#include <iostream>
#include <visp3/visual_features/vpFeaturePoint3D.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpServo task; // Visual servoing task

  // Set the 3D point coordinates in the object frame: oP
  vpPoint point(0.1, -0.1, 0);

  vpHomogeneousMatrix cMo; // Pose between the camera and the object frame
  cMo.buildFrom(0, 0, 1.2, 0, 0, 0);
  // ... cMo need here to be computed from a pose estimation

  point.changeFrame(cMo); // Compute the 3D point coordinates in the camera frame cP = cMo * oP

  // Creation of the current feature s
  vpFeaturePoint3D s;
  s.buildFrom(point); // Initialize the feature from the 3D point coordinates in the camera frame: s=(X,Y,Z)
  s.print();

  // Creation of the desired feature s*.
  vpFeaturePoint3D s_star;
  s_star.buildFrom(0, 0, 1); // Z*=1 meter
  s_star.print();

  // Set eye-in-hand control law.
  // The computed velocities will be expressed in the camera frame
  task.setServo(vpServo::EYEINHAND_CAMERA);
  // Interaction matrix is computed with the desired visual features s*
  task.setInteractionMatrixType(vpServo::DESIRED);
  // Set the constant gain
  double lambda = 0.8;
  task.setLambda(lambda);

  // Add the 3D point feature to the task
  task.addFeature(s, s_star);
  // Add the (X,Y) subset feature from the 3D point visual feature to the task
  // task.addFeature(s, s_star,
  //		  vpFeaturePoint3D::selectX()
  //		  | vpFeaturePoint3D::selectY());

  // Control loop
  for (; ; ) {
    // ... cMo need here to be estimated from for example a pose estimation.
    point.changeFrame(cMo); // Compute the 3D point coordinates in the camera frame cP = cMo * oP

    // Update the current 3D point visual feature
    s.buildFrom(point);

    // compute the control law
    vpColVector v = task.computeControlLaw(); // camera velocity
  }
}
