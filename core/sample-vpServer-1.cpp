#include <visp3/core/vpServer.h>
#include <iostream>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main(int argc, const char **argv)
{
  int port = 35000;
  vpServer serv(port); //Launch the server on localhost
  serv.start();

  bool run = true;
  int val;

  while (run) {
    serv.checkForConnections();

    if (serv.getNumberOfClients() > 0) {
      if (serv.receive(&val) != sizeof(int)) //Receiving a value from the first client
        std::cout << "Error while receiving" << std::endl;
      else
        std::cout << "Received : " << val << std::endl;

      val = val+1;
      if (serv.send(&val) != sizeof(int)) //Sending the new value to the first client
        std::cout << "Error while sending" << std::endl;
      else
        std::cout << "Sending : " << val << std::endl;
    }
  }

  return 0;
}
