#include <visp3/core/vpConfig.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpXmlParserCamera.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // Create a camera parameter container. We want to set these parameters
  // for a 320x240 image, and we want to use the perspective projection
  // modelisation without distortion.
  vpCameraParameters cam;

  // Set the principal point coordinates (u0,v0)
  double u0 = 162.3;
  double v0 = 122.4;
  // Set the pixel ratio (px, py)
  double px = 563.2;
  double py = 564.1;

  // Set the camera parameters for a model without distortion
  cam.initPersProjWithoutDistortion(px, py, u0, v0);

#ifdef VISP_HAVE_PUGIXML
  // Create a XML parser
  vpXmlParserCamera p;
  // Save the camera parameters in an XML file.
  if (p.save(cam, "myNewXmlFile.xml", "myNewCamera", 320, 240) != vpXmlParserCamera::SEQUENCE_OK) {
    std::cout << "Cannot save camera parameters" << std::endl;
  }
#endif
}
