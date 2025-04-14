#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImageTools.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> I;
#ifdef _WIN32
  std::string filename("C:/temp/ViSP-images/Klimt/Klimt.ppm");
#else
  std::string filename("/local/soft/ViSP/ViSP-images/Klimt/Klimt.ppm");
#endif

  // Read an image from the disk
  vpImageIo::read(I, filename);

  // Binarize image I:
  // - gray level values less than or equal to 127 are set to 0,
  // - gray level values greater than 128 are set to 255
  vpImageTools::changeLUT(I, 127, 0, 128, 255);

  vpImageIo::write(I, "Klimt.pgm"); // Write the image in a PGM P5 image file format
}
