#include <visp3/sensor/vpRealSense2.h>

int main() {
#ifdef VISP_HAVE_REALSENSE2
  vpRealSense2 rs;
  rs.open();
  std::cout << "RealSense sensor characteristics: \n" << rs << std::endl;
#endif
  return 0;
}

