//#include <visp3/core/vpCameraParameters.h>
#include <visp3/core/vpXmlParserCamera.h>
#include <visp3/core/vpTime.h>

int main()
{
  vpCameraParameters cam; 
  std::stringstream ss_additional_info;
  ss_additional_info << "<date>" << vpTime::getDateTime() << "</date>";

  vpXmlParserCamera p;
  if (p.save(cam, "camera.xml", "myCamera", 320, 240, ss_additional_info.str()) != vpXmlParserCamera::SEQUENCE_OK) {
    std::cout << "Cannot save camera parameters" << std::endl;
  }
}
