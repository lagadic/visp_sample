#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>

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

  vpMomentObject obj(4); // Create an image moment object with 4 as maximum order
  obj.setType(vpMomentObject::DENSE_POLYGON); // The object is defined by a countour polygon
  obj.fromVector(vec_p); // Init the dense object with the polygon

  return 0;
}
