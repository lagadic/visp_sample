#include <visp3/detection/vpDetectorAprilTag.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_APRILTAG
  vpImage<unsigned char> I;
  vpImageIo::read(I, "image-tag36h11.pgm");

  vpDetectorAprilTag detector(vpDetectorAprilTag::TAG_36h11);
  vpHomogeneousMatrix cMo;
  vpCameraParameters cam;
  cam.initPersProjWithoutDistortion(615.1674805, 615.1675415, 312.1889954, 243.4373779);
  double tagSize_id_0 = 0.04;
  double tagSize_id_others = 0.053;

  bool status = detector.detect(I);
  if (status) {
    for (size_t i = 0; i < detector.getNbObjects(); i++) {
      std::cout << "Tag code " << i << ":" << std::endl;
      std::cout << "  Message: \"" << detector.getMessage(i) << "\"" << std::endl;
      if (detector.getMessage(i) == std::string("36h11 id: 0")) {
        if (!detector.getPose(i, tagSize_id_0, cam, cMo)) {
          std::cout << "Unable to get tag index " << i << " pose!" << std::endl;
        }
      }
      else {
        if (!detector.getPose(i, tagSize_id_others, cam, cMo)) {
          std::cout << "Unable to get tag index " << i << " pose!" << std::endl;
        }
      }
      std::cout << "  Pose: " << vpPoseVector(cMo).t() << std::endl;
    }
  }
#endif
}
