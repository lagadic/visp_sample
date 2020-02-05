#include <visp3/core/vpTime.h>

int main()
{
  double t;
  for (int i=0; i < 100; i++) {
    t = vpTime::measureTimeMs();

    vpTime::wait(t, 40); // Loop time is set to 40 ms, ie 25 Hz
  }

  return 0;
}
