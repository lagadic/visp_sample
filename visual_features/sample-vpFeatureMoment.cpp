#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpMomentBasic.h>
#include <visp3/core/vpMomentDatabase.h>
#include <visp3/visual_features/vpFeatureMoment.h>
#include <visp3/visual_features/vpFeatureMomentBasic.h>

int main()
{
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the vertices

  p.set_x(1); p.set_y(1); // coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(2); p.set_y(2); // coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);

  //////////////////////////////REFERENCE VALUES////////////////////////////////
  vpMomentObject obj(3); // Init object of order 3 because we need
       // vpFeatureMomentBasic of order 2 which
       // implies third-order moment primitives
  obj.setType(vpMomentObject::DISCRETE); // Discrete mode for object
  obj.fromVector(vec_p);

  vpMomentDatabase mdb; //database for moment primitives. This will
      //only contain the basic moment.
  vpMomentBasic bm; //basic moment (this particular moment is nothing
        //more than a shortcut to the vpMomentObject)
  bm.linkTo(mdb); //add basic moment to moment database

  vpFeatureMomentBasic fmb(mdb,0,0,1,NULL);

  //update and compute the vpMoment BEFORE doing any operations with
  //vpFeatureMoment
  bm.update(obj);
  bm.compute();

  fmb.update(0,0,1); //update the vpFeatureMoment with a plane
         //configuration
  std::cout << fmb.interaction(1,1) << std::endl;

  return 0;
}
