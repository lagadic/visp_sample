#include <visp3/core/vpSerial.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifndef WIN32
  {
    vpSerial serial("/dev/ttyUSB0");
    serial.write("Hello world");
  }

  {
    vpSerial serial;
    serial.setPort("/dev/ttyUSB0");
    serial.setBaudrate(9600);
    serial.setBytesize(vpSerial::eightbits);
    serial.setParity(vpSerial::parity_none);
    serial.setStopbits(vpSerial::stopbits_one);
    serial.setFlowcontrol(vpSerial::flowcontrol_none);
    serial.open();

    serial.write("Hello world");
  }
#endif
}
