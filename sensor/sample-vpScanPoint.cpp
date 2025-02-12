#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/sensor/vpScanPoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpScanPoint p;
  double radialDistance = 3; // 3 meters
  double horizontalAngle = 1.12; // 1.12 radian
  double verticalAngle = 0; // 0 radian for a horizontal layer

  p.setPolar(radialDistance, horizontalAngle, verticalAngle);

  std::cout << p << std::endl;
}
