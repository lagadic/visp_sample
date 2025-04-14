#include <visp3/core/vpConfig.h>
#include <visp3/sensor/vpRealSense2.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_REALSENSE2
  vpRealSense2 rs;
  rs.open();
  std::cout << "RealSense sensor characteristics: \n" << rs << std::endl;
#endif
  return 0;
}
