#include <visp3/core/vpConfig.h>
#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Define 4 discrete points on a plane
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the 4 points

  p.set_x(-0.2); p.set_y(0.1); // coordinates in meters in the image plane (point 1)
  vec_p.push_back(p);
  p.set_x(+0.3); p.set_y(0.1); // coordinates in meters in the image plane (point 2)
  vec_p.push_back(p);
  p.set_x(+0.2); p.set_y(-0.1); // coordinates in meters in the image plane (point 3)
  vec_p.push_back(p);
  p.set_x(-0.2); p.set_y(-0.15); // coordinates in meters in the image plane (point 4)
  vec_p.push_back(p);

  vpMomentObject obj(4); // Create an image moment object with 4 as maximum order
  obj.setType(vpMomentObject::DISCRETE); // The object is constituted by discrete points
  obj.fromVector(vec_p); // Init the dense object with the points

  return 0;
}
