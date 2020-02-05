#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpMomentCommon.h>
#include <visp3/core/vpPoint.h>

int main()
{
  // Define an object as 4 clockwise points on a plane (Z=0)
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the 4 points

  vec_p.push_back( vpPoint(-0.2, 0.1, 0.0) ); // values in meters
  vec_p.push_back( vpPoint(+0.3, 0.1, 0.0) ); // values in meters
  vec_p.push_back( vpPoint(+0.2,-0.1, 0.0) ); // values in meters
  vec_p.push_back( vpPoint(-0.2,-0.15, 0.0) ); // values in meters

  // These points are observed by a camera
  vpHomogeneousMatrix cMo(0, 0, 1, 0, 0, 0); // We set the camera to be 1m far the object
  // ... update cMo from an image processing

  // Apply the perspective projection to update the points coordinates in the camera plane
  for(unsigned int i=0; i<vec_p.size(); ++i)
    vec_p[i].project(cMo);

  std::cout << "Considered points: " << std::endl;
  for(unsigned int i=0; i<vec_p.size(); ++i)
    std::cout << "point " << i << ": " << vec_p[i].get_x() << ", " << vec_p[i].get_y() << std::endl;

  // Define an image moment object from the previous points
  vpMomentObject obj(5); // use moments up to order 5
  obj.setType(vpMomentObject::DISCRETE); // initialize the object as constituted by discrete points
  obj.fromVector(vec_p); // init the object from the points

  std::vector<double> moment = obj.get();
  std::cout << std::endl << "Basic moment available: " << std::endl;
  for(unsigned int j=0; j<obj.getOrder(); ++j) {
    for(unsigned int i=0; i<obj.getOrder(); ++i)
      std::cout << "m" << i << j << "=" << moment[j*obj.getOrder() + i] << "  ";
    std::cout << std::endl;
  }

  std::cout << std::endl << "Basic moment avalaible: ";
  std::cout << obj << std::endl;

  std::cout << std::endl << "Direct acces to some basic moments: " << std::endl;
  std::cout << "m00: " << obj.get(0, 0) << std::endl;
  std::cout << "m10: " << obj.get(1, 0) << std::endl;
  std::cout << "m01: " << obj.get(0, 1) << std::endl;
  std::cout << "m22: " << obj.get(2, 2) << std::endl;
  std::cout << "m20: " << obj.get(2, 0) << std::endl;
  std::cout << "m02: " << obj.get(0, 2) << std::endl;

  // Get common moments computed using basic moments
  double m00 = vpMomentCommon::getSurface(obj); // surface = m00
  double alpha = vpMomentCommon::getAlpha(obj); // orientation
  std::vector<double> mu_3 = vpMomentCommon::getMu3(obj); // centered moment up to 3rd order

  std::cout << std::endl << "Common moments computed using basic moments:" << std::endl;
  std::cout << "Surface: " << m00 << std::endl;
  std::cout << "Alpha: " << alpha << std::endl;
  std::cout << "Centered moments (mu03, mu12, mu21, mu30): ";
  for(unsigned int i=0; i<mu_3.size(); ++i)
    std::cout << mu_3[i] << " ";
  std::cout << std::endl;

  return 0;
}
