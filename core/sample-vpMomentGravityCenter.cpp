#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentGravityCenter.h>
#include <iostream>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Define the contour of an object by a 5 clockwise vertices on a plane
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the vertices of the contour polygon

  p.set_x(-0.2); p.set_y(0.1); // coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(+0.3); p.set_y(0.1); // coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  p.set_x(+0.2); p.set_y(-0.1); // coordinates in meters in the image plane (vertex 3)
  vec_p.push_back(p);
  p.set_x(-0.2); p.set_y(-0.15); // coordinates in meters in the image plane (vertex 4)
  vec_p.push_back(p);
  p.set_x(-0.2); p.set_y(0.1); // close the contour (vertex 5 = vertex 1)
  vec_p.push_back(p);

  vpMomentObject obj(1); // Create an image moment object with 1 as
       // maximum order (because only m00,m01,m10
       // are needed to compute the gravity center primitive.
  obj.setType(vpMomentObject::DENSE_POLYGON); // The object is defined by a countour polygon
  obj.fromVector(vec_p); // Init the dense object with the polygon

  vpMomentGravityCenter g; // declaration of gravity center
  g.update(obj); // specify the object
  g.compute(); // compute the moment

  std::cout << "Xg=" << g.getXg() << std::endl; // access to Xg
  std::cout << "Yg=" << g.getYg() << std::endl; // access to Yg

  std::cout << g << std::endl; // print gravity center

  return 0;
}
