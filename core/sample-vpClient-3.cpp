#include <iostream>
#include <string.h>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpClient.h>
#include <visp3/core/vpColVector.h>
#include <visp3/core/vpRequest.h>


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

/* end vpRequestImage.h */

/* begin vpRequestImage.cpp */
//#include "vpRequestImage.h"

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
  addParameterObject(vec->data, size*sizeof(double));
}

void vpRequestVector::decode()
{
  if (listOfParams.size() == 1) {
    unsigned int size;
    memcpy((void *)&size, (void *)listOfParams[0].c_str(), sizeof(unsigned int));

    vec->resize(size);
    memcpy((void *)vec->data, (void *)listOfParams[1].c_str(), size*sizeof(double));
  }
}

/* end vpRequestImage.cpp */

int main()
{
#if defined(VISP_HAVE_V4L2)
  std::string servername = "localhost";
  unsigned int port = 35000;

  vpColVector vec(3);

  vpClient client;
  client.connectToHostname(servername, port);
  //client.connectToIP("127.0.0.1",port);

  vpRequestVector reqVector(&vec);

  while (1) {
    double t = vpTime::measureTimeMs();
    client.sendAndEncodeRequest(reqVector);
  }

  return 0;
#endif
}
