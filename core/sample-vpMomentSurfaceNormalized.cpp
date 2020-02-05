#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentGravityCenter.h>
#include <visp3/core/vpMomentDatabase.h>
#include <visp3/core/vpMomentCentered.h>
#include <visp3/core/vpMomentAreaNormalized.h>

int main()
{  
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains object points

  p.set_x(1); p.set_y(1); // coordinates in meters in the image plane of point 1
  vec_p.push_back(p);
  p.set_x(2); p.set_y(2); // coordinates in meters in the image plane of point 2
  vec_p.push_back(p);

  //////////////////////////////REFERENCE VALUES////////////////////////////////
  vpMomentObject obj(2); // Object where all the moment defined with
			 // i+j <= 2 will be computed below. Order is
			 // 2 because in discrete mode, the surface
			 // computation is a=mu02+mu02
  
  
  obj.setType(vpMomentObject::DISCRETE); // Discrete mode for object
  obj.fromVector(vec_p); // initialize the object with the points coordinates

  vpMomentDatabase db; //reference database
  vpMomentGravityCenter g; // declaration of gravity center
  vpMomentCentered mc; //  centered moments
  vpMomentAreaNormalized an(2,1); //declare normalized surface with
                                //destination depth of 1 meter and
                                //destination surface of 2 m2

  g.linkTo(db); //add gravity center to database
  mc.linkTo(db); //add centered moments
  an.linkTo(db); //add alpha depending on centered moments

  db.updateAll(obj); // All of the moments must be updated, not just an

  g.compute(); // compute the moment
  mc.compute(); //compute centered moments AFTER gravity center
  an.compute(); //compute alpha AFTER centered moments.

  std::cout << an << std::endl;

  return 0;
}
