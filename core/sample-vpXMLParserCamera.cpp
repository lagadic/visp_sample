#include <visp3/core/vpConfig.h>
#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpXmlParserCamera.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpCameraParameters cam; // Create a camera parameter container

#ifdef VISP_HAVE_PUGIXML
  vpXmlParserCamera p; // Create a XML parser
  vpCameraParameters::vpCameraParametersProjType projModel; // Projection model
  // Use a perspective projection model without distortion
  projModel = vpCameraParameters::perspectiveProjWithoutDistortion;
  // Parse the xml file "myXmlFile.xml" to find the intrinsic camera
  // parameters of the camera named "myCamera" for the image sizes 640x480,
  // for the projection model projModel. The size of the image is optional
  // if camera parameters are given only for one image size.
  if (p.parse(cam, "myXmlFile.xml", "myCamera", projModel, 640, 480) != vpXmlParserCamera::SEQUENCE_OK) {
    std::cout << "Cannot found myCamera" << std::endl;
  }

  // cout the parameters
  cam.printParameters();

  // Get the camera parameters for the model without distortion
  double px = cam.get_px();
  double py = cam.get_py();
  double u0 = cam.get_u0();
  double v0 = cam.get_v0();

  // Now we modify the principal point (u0,v0) for example to add noise
  u0 *= 0.9;
  v0 *= 0.8;

  // Set the new camera parameters
  cam.initPersProjWithoutDistortion(px, py, u0, v0);

  // Save the parameters in a new file "myXmlFileWithNoise.xml"
  p.save(cam, "myXmlFileWithNoise.xml", p.getCameraName(), p.getWidth(), p.getHeight());
#endif
}
