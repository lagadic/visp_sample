#include <visp3/sensor/vpRealSense2.h>
int main() {
  vpRealSense2 rs;
  rs.open();
    std::cout << "RealSense sensor characteristics: \n" << rs << std::endl;
  return 0;
}

