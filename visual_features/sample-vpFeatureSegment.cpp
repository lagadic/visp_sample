#include <visp3/visual_features/vpFeatureSegment.h>
#include <visp3/core/vpPoint.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Define two 3D points in the object frame
  vpPoint p1, p2;
  p1.setWorldCoordinates(.1, .1, 0.);
  p2.setWorldCoordinates(.3, .2, 0.);

  // Define the camera pose wrt the object
  vpHomogeneousMatrix cMo(0, 0, 1, 0, 0, 0); // Z=1 meter
  // Compute the coordinates of the points in the camera frame
  p1.changeFrame(cMo);
  p2.changeFrame(cMo);
  // Compute the coordinates of the points in the image plane by perspective projection
  p1.project();
  p2.project();

  // Build the segment visual feature
  vpFeatureSegment s;
  s.buildFrom(p1.get_x(), p1.get_y(), p1.get_Z(), p2.get_x(), p2.get_y(), p2.get_Z());

  s.print();

  // Compute the interaction matrix
  vpMatrix L = s.interaction(vpBasicFeature::FEATURE_ALL);

  std::cout << "L: " << L << std::endl;

  vpMatrix L2 = s.interaction(vpFeatureSegment::selectL() | vpFeatureSegment::selectAlpha());

  std::cout << "L: " << L2 << std::endl;
  s.print(vpFeatureSegment::selectL() | vpFeatureSegment::selectAlpha());

  vpFeatureSegment s_star;
  vpServo task;
  task.addFeature(s, s_star, vpFeatureSegment::selectAlpha());
}
