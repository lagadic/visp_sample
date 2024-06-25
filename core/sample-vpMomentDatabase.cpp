#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentGravityCenter.h>
#include <visp3/core/vpMomentDatabase.h>
#include <visp3/core/vpMomentCentered.h>
#include <iostream>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the vertices of the contour polygon

  p.set_x(1); p.set_y(1); // coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(2); p.set_y(2); // coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  vpMomentObject obj(1); // Create an image moment object with 1 as
       // maximum order (sufficient for gravity center)
  obj.setType(vpMomentObject::DISCRETE); // The object is defined by
           // two discrete points
  obj.fromVector(vec_p); // Init the dense object with the polygon

  vpMomentDatabase db;
  vpMomentGravityCenter g; // declaration of gravity center
  vpMomentCentered mc; // mc containts centered moments

  g.linkTo(db); //add gravity center to database
  mc.linkTo(db); //centered moments depend on gravity, add them to the
     //database to grant access

  db.updateAll(obj); // All of the moments must be updated, not just mc

  //There is no global compute method since the order of compute calls
  //depends on the implementation
  g.compute(); // compute the moment
  mc.compute(); //compute centered moments AFTER gravity center

  std::cout << "Gravity center: " << g << std::endl; // print gravity center moment
  std::cout << "Centered moments: " << mc << std::endl; // print centered moment

  return 0;
}
