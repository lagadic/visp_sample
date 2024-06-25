#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpMomentBasic.h>
#include <visp3/core/vpMomentCInvariant.h>
#include <visp3/core/vpMomentCentered.h>
#include <visp3/core/vpMomentCInvariant.h>
#include <visp3/core/vpMomentGravityCenter.h>
#include <visp3/core/vpMomentDatabase.h>

#include <visp3/visual_features/vpFeatureMomentCInvariant.h>
#include <visp3/visual_features/vpFeatureMomentBasic.h>
#include <visp3/visual_features/vpFeatureMomentCentered.h>
#include <visp3/visual_features/vpFeatureMomentDatabase.h>
#include <iostream>
#include <vector>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  try {

    vpPoint p;
    std::vector<vpPoint> vec_p; // vector that contains the vertices

    p.set_x(1); p.set_y(1); // coordinates in meters in the image plane (vertex 1)
    vec_p.push_back(p);
    p.set_x(2); p.set_y(2); // coordinates in meters in the image plane (vertex 2)
    vec_p.push_back(p);

    //////////////////////////////REFERENCE VALUES////////////////////////////////
    vpMomentObject obj(6); // Init object of order 6 because we are
         // computing C-invariants
    obj.setType(vpMomentObject::DISCRETE); // Discrete mode for object
    obj.fromVector(vec_p);


    vpMomentDatabase mdb; //database for moment primitives. This will
                          //only contain the basic moment.
    vpMomentCentered mc; //Centered moment
    vpMomentBasic bm; //Basic moment
    vpMomentGravityCenter gc; //gravity center
    vpMomentCInvariant ci; //C-type invariant

    bm.linkTo(mdb); //add basic moment to moment database
    mc.linkTo(mdb);  //add centered moment to moment database
    gc.linkTo(mdb); //add gravity center to moment database
    ci.linkTo(mdb); //add C-invariant to moment database

    vpFeatureMomentDatabase fmdb; //feature moment database to store
                                  //feature dependencies

    //Declare and link moments to database
    vpFeatureMomentBasic fmb(mdb, 0., 0., 1., &fmdb); fmb.linkTo(fmdb);
    vpFeatureMomentCentered fmc(mdb, 0., 0., 1., &fmdb); fmc.linkTo(fmdb);
    vpFeatureMomentCInvariant fci(mdb, 0., 0., 1., &fmdb); fci.linkTo(fmdb);


    //update the whole moment database
    mdb.updateAll(obj);

    //Compute moments in the correct order with the object
    bm.compute();
    gc.compute();
    mc.compute();
    ci.compute();

    //update the whole feature moment database with a plane
    fmb.update(0., 0., 1.);
    fmc.update(0., 0., 1.);
    fci.update(0., 0., 1.);

    std::cout << fci.interaction(vpFeatureMomentCInvariant::selectC1()) << std::endl;
  }
  catch (vpException e) {
    std::cout << e.getMessage() << std::endl;
  }

  return 0;
}
