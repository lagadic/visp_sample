#include <visp3/robot/vpRingLight.h>
#include <visp3/core/vpTime.h>

int main()
{
#ifdef VISP_HAVE_PARPORT
  vpRingLight light;         // Open the device to access to the ring light.

  int nsec = 10;             // Time to wait in seconds
  light.on();                // Turn the ring light on
  vpTime::wait(nsec * 1000); // Wait 10 s
  light.off();               // and then turn the ring light off
#endif
}
