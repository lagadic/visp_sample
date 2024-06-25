#include <visp3/core/vpTime.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  double t;
  for (int i = 0; i < 100; i++) {
    t = vpTime::measureTimeMs();

    vpTime::wait(t, 40); // Loop time is set to 40 ms, ie 25 Hz
  }

  return 0;
}
