#include <visp3/core/vpConfig.h>
#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentGravityCenter.h>
#include <visp3/core/vpMomentDatabase.h>
#include <visp3/core/vpMomentCentered.h>
#include <visp3/core/vpMomentAlpha.h>

//generic function for printing
void print(double i) { std::cout << i << "\t"; }

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpPoint p;
  std::vector<vpPoint> vec_p; // Vector that contains the vertices of the contour polygon
  p.set_x(1); p.set_y(1);     // Coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(2); p.set_y(2);     // Coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  p.set_x(-3); p.set_y(0);    // Coordinates in meters in the image plane (vertex 3)
  vec_p.push_back(p);
  p.set_x(-3); p.set_y(-1);   // Coordinates in meters in the image plane (vertex 4)
  vec_p.push_back(p);

  //////////////////////////////REFERENCE VALUES////////////////////////////////
  vpMomentObject objRef(3);                      // Reference object. Must be of order 3 because we will
  // need the 3rd order centered moments

  objRef.setType(vpMomentObject::DENSE_POLYGON); // Object is the inner part of a polygon
  objRef.fromVector(vec_p);                      // Init the dense object with the polygon

  vpMomentDatabase dbRef;                        // Reference database
  vpMomentGravityCenter gRef;                    // Declaration of gravity center
  vpMomentCentered mcRef;                        // Centered moments
  vpMomentAlpha alphaRef;                        // Declare alpha as reference

  gRef.linkTo(dbRef);                            // Add gravity center to database
  mcRef.linkTo(dbRef);                           // Add centered moments
  alphaRef.linkTo(dbRef);                        // Add alpha depending on centered moments

  dbRef.updateAll(objRef);                       // All of the moments must be updated, not just alpha

  gRef.compute();                                // Compute the moment
  mcRef.compute();                               // Compute centered moments AFTER gravity center
  alphaRef.compute();                            // Compute alpha AFTER centered moments.

  // The order of values in the vector must be as follows: mu30 mu21 mu12 mu03
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::vector<double> mu3ref = { mcRef.get(3,0), mcRef.get(2,1), mcRef.get(1,2), mcRef.get(0,3) };
#else
  std::vector<double> mu3ref;
  mu3ref.push_back(mcRef.get(3, 0));
  mu3ref.push_back(mcRef.get(2, 1));
  mu3ref.push_back(mcRef.get(1, 2));
  mu3ref.push_back(mcRef.get(0, 3));
#endif
  std::cout << "--- Reference object ---" << std::endl;
  std::cout << "alphaRef=" << vpMath::deg(alphaRef.get()) << " deg" << std::endl << "mu3="; // print reference alpha
  std::for_each(mu3ref.begin(), mu3ref.end(), print);
  std::cout << std::endl;

  ////////////CURRENT VALUES (same object rotated 180deg - must be
  ////////////entered in reverse order)////////////////
  vec_p.clear();

  p.set_x(-1); p.set_y(-1);                      // Coordinates in meters in the image plane (vertex 4)
  vec_p.push_back(p);
  p.set_x(-2); p.set_y(-2);                       // Coordinates in meters in the image plane (vertex 3)
  vec_p.push_back(p);
  p.set_x(3); p.set_y(-0);                       // Coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  p.set_x(3); p.set_y(1);                        // Coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);

  vpMomentObject obj(3);                         // Second object. Order 3 is also required because of the Alpha
  // will compare third-order centered moments to given reference.

  obj.setType(vpMomentObject::DENSE_POLYGON);    // Object is the inner part of a polygon
  obj.fromVector(vec_p);                         // Init the dense object with the polygon

  vpMomentDatabase db;                           // Database
  vpMomentGravityCenter g;                       // Declaration of gravity center
  vpMomentCentered mc;                           // mc containts centered moments
  vpMomentAlpha alpha(mu3ref, alphaRef.get());   // Declare alpha as relative to a reference

  g.linkTo(db);                                  // Add gravity center to database
  mc.linkTo(db);                                 // Add centered moments
  alpha.linkTo(db);                              // Add alpha depending on centered moments

  db.updateAll(obj);                             // All of the moments must be updated

  g.compute();                                   // Compute the moment
  mc.compute();                                  // Compute centered moments AFTER gravity center
  alpha.compute();                               // Compute alpha AFTER centered moments.

  std::cout << "--- current object ---" << std::endl;
  std::cout << "alpha=" << vpMath::deg(alpha.get()) << " deg" << std::endl;

  return 0;
}
