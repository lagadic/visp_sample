#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/robot/vpServolens.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))) // UNIX
  // Open the serial device to communicate with the Servolens lens
  vpServolens servolens("/dev/ttyS0");

  // Get the current zoom position
  unsigned zoom;
  servolens.getPosition(vpServolens::ZOOM, zoom);
  std::cout << "Actual zoom value: " << zoom << std::endl;

  // Set a new zoom value
  servolens.setPosition(vpServolens::ZOOM, zoom+1000);
#endif
}
