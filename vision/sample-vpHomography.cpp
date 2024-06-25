#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/vision/vpHomography.h>
#include <visp3/core/vpMath.h>
#include <visp3/core/vpMeterPixelConversion.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Initialize in the object frame the coordinates in meters of 4 points that
  // belong to a planar object
  vpPoint Po[4];
  Po[0].setWorldCoordinates(-0.1, -0.1, 0);
  Po[1].setWorldCoordinates(0.2, -0.1, 0);
  Po[2].setWorldCoordinates(0.1, 0.1, 0);
  Po[3].setWorldCoordinates(-0.1, 0.3, 0);

  // Initialize the pose between camera frame a and object frame o
  vpHomogeneousMatrix aMo(0, 0, 1, 0, 0, 0); // Camera is 1 meter far

  // Initialize the pose between camera frame a and camera frame
  // b. These two frames correspond for example to two successive
  // camera positions
  vpHomogeneousMatrix aMb(0.2, 0.1, 0, 0, 0, vpMath::rad(2));

  // Compute the pose between camera frame b and object frame
  vpHomogeneousMatrix bMo = aMb.inverse() * aMo;

  // Initialize camera intrinsic parameters
  vpCameraParameters cam;

  // Compute the coordinates in pixels of the 4 object points in the
  // camera frame a
  vpPoint Pa[4];
  std::vector<double> xa(4), ya(4); // Coordinates in pixels of the points in frame a
  for (int i = 0; i < 4; i++) {
    Pa[i] = Po[i];
    Pa[i].project(aMo); // Project the points from object frame to
      // camera frame a
    vpMeterPixelConversion::convertPoint(cam, Pa[i].get_x(), Pa[i].get_y(), xa[i], ya[i]);
  }

  // Compute the coordinates in pixels of the 4 object points in the
  // camera frame b
  vpPoint Pb[4];
  std::vector<double> xb(4), yb(4); // Coordinates in pixels of the points in frame b
  for (int i = 0; i < 4; i++) {
    Pb[i] = Po[i];
    Pb[i].project(bMo); // Project the points from object frame to
            // camera frame a
  }

  // Compute equation of the 3D plane containing the points in camera frame b
  vpPlane bP(Pb[0], Pb[1], Pb[2]);

  // Compute the corresponding ground truth homography
  vpHomography aHb(aMb, bP);

  std::cout << "Ground truth homography aHb: \n" << aHb<< std::endl;

  // Compute the coordinates of the points in frame b using the ground
  // truth homography and the coordinates of the points in frame a
  vpHomography bHa = aHb.inverse();
  for (int i = 0; i < 4; i++) {
    double inv_z = 1. / (bHa[2][0] * xa[i] + bHa[2][1] * ya[i] + bHa[2][2]);

    xb[i] = (bHa[0][0] * xa[i] + bHa[0][1] * ya[i] + bHa[0][2]) * inv_z;
    yb[i] = (bHa[1][0] * xa[i] + bHa[1][1] * ya[i] + bHa[1][2]) * inv_z;
  }

//   for(int i=0 ; i < 4 ; i++) {
//     std::cout << "[" << i << "] : " << xa[i] << " " << ya[i]
// 	      << " ; " << xb[i] << " " << yb[i] << std::endl;
//   }

  // Estimate the homography from 4 points coordinates expressed in pixels
  vpHomography::DLT(xb, yb, xa, ya, aHb, true);
  aHb /= aHb[2][2]; // Apply a scale factor to have aHb[2][2] = 1

  std::cout << "Estimated homography aHb: \n" << aHb<< std::endl;
}
