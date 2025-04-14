
#include <string.h>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpServer.h>

#include <visp/vpDebug.h>
#include <visp3/core/vpException.h>
#include <visp3/core/vpColVector.h>
#include <visp/vpRequest.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif
class vpRequestVector : public vpRequest
{
private:
  vpColVector *vec;

public:
  vpRequestVector();
  vpRequestVector(vpColVector *);
  ~vpRequestVector();

  virtual void encode();
  virtual void decode();
};

vpRequestVector::vpRequestVector()
{
  request_id = "vector";
}

vpRequestVector::vpRequestVector(vpColVector *v)
{
  request_id = "vector";
  vec = v;
}

vpRequestVector::~vpRequestVector() { }

void vpRequestVector::encode()
{
  clear();

  unsigned int size = vec->getRows();

  addParameterObject(&size);
}

void vpRequestVector::decode()
{
  if (listOfParams.size() == 1) {
    unsigned int size;
    memcpy((void *)&size, (void *)listOfParams[0].c_str(), sizeof(unsigned int));
    std::cout << size << std::endl;
  }
}

/* end vpRequestImage.cpp */

int main(int argc, const char **argv)
{
  int port = 35000;

  std::cout << "Port: " << port << std::endl;
  vpServer serv(port);
  serv.start();

  vpColVector vec;

  vpRequestVector reqVector(&vec);
  serv.addDecodingRequest(&reqVector);

  bool run = true;

  while (run) {
    serv.checkForConnections();

    if (serv.getNumberOfClients() > 0) {
      int index = serv.receiveAndDecodeRequestOnce();
      std::string id = serv.getRequestIdFromIndex(index);

      if (id == "vector") {

      }
    }
  }

  return 0;
}
