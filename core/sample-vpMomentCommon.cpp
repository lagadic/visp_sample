#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentCInvariant.h>
#include <visp3/core/vpMomentCommon.h>
#include <iostream>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Define two discrete points
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the vertices of the contour polygon

  p.set_x(1); p.set_y(1); // coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(2); p.set_y(2); // coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  p.set_x(-3); p.set_y(0); // coordinates in meters in the image plane (vertex 3)
  vec_p.push_back(p);
  p.set_x(-3); p.set_y(1); // coordinates in meters in the image plane (vertex 4)
  vec_p.push_back(p);

  vpMomentObject obj(5); // Object initialized up to order 5 to handle
       // all computations required by vpMomentCInvariant
  obj.setType(vpMomentObject::DENSE_POLYGON); // object is the inner part of a polygon
  obj.fromVector(vec_p); // Init the discrete object with two points

  //initialisation with default values
  vpMomentCommon db(vpMomentCommon::getSurface(obj), vpMomentCommon::getMu3(obj), vpMomentCommon::getAlpha(obj), 1.);
  bool success;

  db.updateAll(obj); // Update AND compute all moments

  //get C-invariant
  const vpMomentCInvariant &C = static_cast<const vpMomentCInvariant &>(db.get("vpMomentCInvariant", success));
  if (success) {
    std::cout << C.get(0) << std::endl;
  }
  else
    std::cout << "vpMomentCInvariant not found." << std::endl;

  return 0;
}
