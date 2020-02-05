#include <iostream>
#include <visp3/visual_features/vpFeaturePoint3D.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpMatrix.h>

int main()
{
  // Set the 3D point coordinates in the object frame: oP
  vpPoint point(0.1, -0.1, 0);

  vpHomogeneousMatrix cMo; // Pose between the camera and the object frame
  cMo.buildFrom(0, 0, 1.2, 0, 0, 0); 
  // ... cMo need here to be computed from a pose estimation

  point.changeFrame(cMo); // Compute the 3D point coordinates in the camera frame cP = cMo * oP

  // Creation of the current feature s
  vpFeaturePoint3D s;
  s.buildFrom(point); // Initialize the feature from the 3D point coordinates in the camera frame 
  s.print();

  // Creation of the desired feature s*. 
  vpFeaturePoint3D s_star;
  s_star.buildFrom(0, 0, 1); // Z*=1 meter
  s_star.print();

  // Compute the L_s interaction matrix associated to the current feature
  vpMatrix L = s.interaction();
  std::cout << "L: " << L << std::endl;

  // Compute the error vector (s-s*) for the 3D point feature
  vpColVector e = s.error(s_star); // e = (s-s*)

  std::cout << "e: " << e << std::endl;
}
