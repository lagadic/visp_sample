#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>

int main()
{
  vpImage<unsigned char> I;
#ifdef _WIN32
  std::string filename("C:/temp/ViSP-images/Klimt/Klimt.ppm");
#else
  std::string filename("/local/soft/ViSP/ViSP-images/Klimt/Klimt.ppm");
#endif

  vpImageIo::read(I, filename); // Convert the color image in a gray level image
  vpImageIo::write(I, "Klimt.pgm"); // Write the image in a PGM P5 image file format 
}
