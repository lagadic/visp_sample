#include <visp3/core/vpImage.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  // gray
  {
    vpImage<unsigned char> I(1, 2);
    I[0][0] = 1;
    I[0][1] = 2;

    std::cout << "Gray image mean value: " << I.getMeanValue() << std::endl;
    std::cout << "Gray image global mean value: " << I.getMeanValue() << std::endl; // nchannels = 1
  }
  // color
  {
    vpImage<vpRGBa> I(1, 2);
    I[0][0].R = 1;
    I[0][0].G = 2;
    I[0][0].B = 3;
    I[0][1].R = 4;
    I[0][1].G = 5;
    I[0][1].B = 6;

    int nchannels = 3;
    std::cout << "RGBa color image mean value: " << I.getMeanValue() << std::endl;
    std::cout << "RGBa color image global mean value: " << I.getMeanValue() / nchannels << std::endl;
  }

  return EXIT_SUCCESS;
}
