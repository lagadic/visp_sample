#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpImage.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpCameraParameters cam;             // Camera parameters used for pixel to meter conversion
  vpImage<unsigned char> I(288, 384); // Image used to define the object
  // ... Initialize the image

  unsigned char threshold = 128; // Gray level used to define which part of the image belong to the dense object

  vpMomentObject obj(3); // Create an image moment object with 3 as maximum order
  obj.fromImage(I, threshold, cam); // Initialize the object from the image

  return 0;
}
