#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpPoint.h>
#include <visp3/visual_features/vpFeatureBuilder.h>
#include <visp3/visual_features/vpFeaturePointPolar.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Create 4 points to specify the object of interest
  vpPoint point[4];

  // Set the 3D point coordinates in the object frame: oP
  point[0].setWorldCoordinates(-0.1, -0.1, 0);
  point[1].setWorldCoordinates(0.1, -0.1, 0);
  point[2].setWorldCoordinates(0.1, 0.1, 0);
  point[3].setWorldCoordinates(-0.1, 0.1, 0);

  // Initialize the desired pose between the camera and the object frame
  vpHomogeneousMatrix cMod;
  cMod.buildFrom(0, 0, 1, 0, 0, 0);

  // Compute the desired position of the point
  for (int i = 0; i < 4; i++) {
    // Compute the 3D point coordinates in the camera frame cP = cMod * oP
    point[i].changeFrame(cMod);
    // Compute the perspective projection to set (x,y)
    point[i].projection();
  }

  // Create 4 desired visual features as 2D points with polar coordinates
  vpFeaturePointPolar pd[4];
  // Initialize the desired visual feature from the desired point positions
  for (int i = 0; i < 4; i++)
    vpFeatureBuilder::create(pd[i], point[i]);

  // Initialize the current pose between the camera and the object frame
  vpHomogeneousMatrix cMo;
  cMo.buildFrom(0, 0, 1.2, 0, 0, M_PI);
  // ... cMo need here to be computed from a pose estimation

  for (int i = 0; i < 4; i++) {
    // Compute the 3D point coordinates in the camera frame cP = cMo * oP
    point[i].changeFrame(cMo);
    // Compute the perspective projection to set (x,y)
    point[i].projection();
  }
  // Create 4 current visual features as 2D points with polar coordinates
  vpFeaturePointPolar p[4];
  // Initialize the current visual feature from the current point positions
  for (int i = 0; i < 4; i++)
    vpFeatureBuilder::create(p[i], point[i]);

  // Visual servo task initialization
  vpServo task;
  // - Camera is monted on the robot end-effector and velocities are
  //   computed in the camera frame
  task.setServo(vpServo::EYEINHAND_CAMERA);
  // - Interaction matrix is computed with the current visual features s
  task.setInteractionMatrixType(vpServo::CURRENT);
  // - Set the contant gain to 1
  task.setLambda(1);
  // - Add current and desired features
  for (int i = 0; i < 4; i++)
    task.addFeature(p[i], pd[i]);

  // Control loop
  for (; ; ) {
    // ... cMo need here to be estimated from for example a pose estimation.
    // Computes the point coordinates in the camera frame and its 2D
    // coordinates in the image plane
    for (int i = 0; i < 4; i++)
      point[i].track(cMo);

    // Update the current 2D point visual feature with polar coordinates
    for (int i = 0; i < 4; i++)
      vpFeatureBuilder::create(p[i], point[i]);

    // compute the control law
    vpColVector v = task.computeControlLaw(); // camera velocity
  }

  task.kill();
}
