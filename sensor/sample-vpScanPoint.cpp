#include <iostream>
#include <visp3/sensor/vpScanPoint.h>

int main()
{
  vpScanPoint p;
  double radialDistance = 3; // 3 meters
  double horizontalAngle = 1.12; // 1.12 radian
  double verticalAngle = 0; // 0 radian for a horizontal layer

  p.setPolar(radialDistance, horizontalAngle, verticalAngle);

  std::cout << p << std::endl;
}

