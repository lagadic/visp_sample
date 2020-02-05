#include <visp3/io/vpParallelPort.h>

int main()
{
#ifdef VISP_HAVE_PARPORT
  vpParallelPort parport;

  unsigned char data = 5; // 0x00000101 = 5 in decimal
  parport.sendData(data); // D0 and D2 are set to logical level 1
#endif
}
