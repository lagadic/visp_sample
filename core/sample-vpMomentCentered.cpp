#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpPoint.h>
#include <visp3/core/vpMomentGravityCenter.h>
#include <visp3/core/vpMomentDatabase.h>
#include <visp3/core/vpMomentCentered.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpPoint p;
  std::vector<vpPoint> vec_p;

  p.set_x(1); p.set_y(1); // coordinates in meters in the image plane
  vec_p.push_back(p);
  p.set_x(2); p.set_y(2); // coordinates in meters in the image plane

  vpMomentObject obj(3); //init object up to order 3
  obj.setType(vpMomentObject::DISCRETE); // Discrete mode.
  obj.fromVector(vec_p); // Init object with the two points

  vpMomentDatabase db;
  vpMomentGravityCenter g; // declaration of gravity center
  vpMomentCentered mc; // mc containts centered moments

  g.linkTo(db); //add gravity center to database
  mc.linkTo(db); //centered moments depend on gravity, add them to the
                 //database to grant access

  g.update(obj); // specify the object for gravity center
  mc.update(obj); // and for centered moments

  g.compute(); // compute the moment
  mc.compute(); //compute centered moments AFTER gravity center

  double m12;
  m12 = mc.get()[2*(obj.getOrder()+1)+1]; // i=1 and j=2
  std::cout << m12 << std::endl;
  m12 = mc.get(1, 2); // the same
  std::cout << m12 << std::endl;
  return 0;
}
