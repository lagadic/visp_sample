#include <visp3/io/vpImageIo.h>
#include <visp3/core/vpImageConvert.h>

int main()
{
  vpImage<vpRGBa> I;
  vpImageIo::read(I, "ballons.jpg");

  unsigned int width = I.getWidth();
  unsigned int height = I.getHeight();

  vpImage<unsigned char> H(height, width);
  vpImage<unsigned char> S(height, width);
  vpImage<unsigned char> V(height, width);

  vpImageConvert::RGBaToHSV(reinterpret_cast<unsigned char *>(I.bitmap),
                            reinterpret_cast<unsigned char *>(H.bitmap),
                            reinterpret_cast<unsigned char *>(S.bitmap),
                            reinterpret_cast<unsigned char *>(V.bitmap), I.getSize());
}
