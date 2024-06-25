#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // gray
  {
    vpImage<unsigned char> I;
    vpImageIo::read(I, "Klimt.pgm");

    vpImage<unsigned char> Isampled;
    I.subsample(2, 2, Isampled);

    vpImageIo::write(Isampled, "Klimt-sampled.pgm");
  }
  // color
  {
    vpImage<vpRGBa> I;
    vpImageIo::read(I, "Klimt.ppm");

    vpImage<vpRGBa> Isampled;
    I.subsample(2, 2, Isampled);

    vpImageIo::write(Isampled, "Klimt-sampled.ppm");
  }

  return 0;
}
