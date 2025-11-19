#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/sensor/vpSickLDMRS.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))) // UNIX
  std::string ip = "131.254.12.119";

  vpSickLDMRS laser;
  laser.setIpAddress(ip);
  laser.setup();

  vpLaserScan laserscan[4];
  for (; ; ) {
    // Get the measured points in the four layers
    laser.measure(laserscan);

    // Prints all the measured points
    for (int layer = 0; layer<4; layer++) {
      std::vector<vpScanPoint> pointsInLayer = laserscan[layer].getScanPoints();
      vpScanPoint p;

      for (unsigned int i = 0; i < pointsInLayer.size(); i++) {
        std::cout << pointsInLayer[i] << std::endl;
      }
    }
  }
#endif
}
