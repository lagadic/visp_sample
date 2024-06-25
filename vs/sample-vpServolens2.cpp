#include <visp3/robot/vpServolens.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))) // UNIX
  vpServolens servolens("/dev/ttyS0");

  vpImage<unsigned char> I(240, 320);
  vpCameraParameters cam = servolens.getCameraParameters(I);
  std::cout << "Camera parameters: " << cam << std::endl;
#endif
}
