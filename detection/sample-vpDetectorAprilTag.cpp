#include <visp3/detection/vpDetectorAprilTag.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#ifdef VISP_HAVE_APRILTAG
  vpImage<unsigned char> I;
  vpImageIo::read(I, "image-tag36h11.pgm");

  vpDetectorAprilTag detector(vpDetectorAprilTag::TAG_36h11);

  bool status = detector.detect(I);
  if (status) {
    for(size_t i=0; i < detector.getNbObjects(); i++) {
      std::cout << "Tag code " << i << ":" << std::endl;
      std::vector<vpImagePoint> p = detector.getPolygon(i);
      for(size_t j=0; j < p.size(); j++)
        std::cout << "  Point " << j << ": " << p[j] << std::endl;
      std::cout << "  Message: \"" << detector.getMessage(i) << "\"" << std::endl;
    }
  }
#endif
}
