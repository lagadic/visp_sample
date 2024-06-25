#include <iostream>
#include <visp3/core/vpClient.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::string servername = "localhost";
  unsigned int port = 35000;

  vpClient client;
  client.connectToHostname(servername, port);
  //client.connectToIP("127.0.0.1",port);

  int val = 0;

  while (1) {
    // Sending the new value to the first client
    if (client.send(&val) != sizeof(int))
      std::cout << "Error while sending" << std::endl;
    else
      std::cout << "Sending : " << val << std::endl;

    // Receiving a value from the first client
    if (client.receive(&val) != sizeof(int))
      std::cout << "Error while receiving" << std::endl;
    else
      std::cout << "Received : " << val << std::endl;
  }

  return 0;
}
