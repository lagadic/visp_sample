#include <visp3/core/vpConfig.h>
#include <visp3/detection/vpDetectorQRCode.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_ZBAR
  vpImage<unsigned char> I;
  vpImageIo::read(I, "bar-code.pgm");

  vpDetectorQRCode detector;

  bool status = detector.detect(I);
  if (status) {
    for (size_t i = 0; i < detector.getNbObjects(); i++) {
      std::cout << "Bar code " << i << ":" << std::endl;
      std::vector<vpImagePoint> p = detector.getPolygon(i);
      for (size_t j = 0; j < p.size(); j++)
        std::cout << "  Point " << j << ": " << p[j] << std::endl;
      std::cout << "  Message: \"" << detector.getMessage(i) << "\"" << std::endl;
    }
  }
#endif
}
