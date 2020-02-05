#include <visp3/core/vpConfig.h>
#ifdef VISP_HAVE_REALSENSE

#include <visp3/sensor/vpRealSense.h>
#include <visp3/gui/vpPlot.h>

int main()
{
  vpRealSense rs;
  rs.open();
  std::cout << rs << std::endl;

  std::vector<vpColVector> pointcloud;
  while (1) {
    rs.acquire(pointcloud);
  }
}

#else
int main() {}
#endif

