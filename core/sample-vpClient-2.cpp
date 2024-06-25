#include <visp3/core/vpClient.h>
#include <visp3/sensor/vpV4l2Grabber.h>
#include <visp3/core/vpImage.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <iostream>

//#include "vpRequestImage.h" //See vpRequest class documentation

/* begin vpRequestImage.h */

#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageException.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/core/vpRequest.h>
#include <string.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif
class vpRequestImage : public vpRequest
{
private:
  vpImage<unsigned char> *I;

public:
  vpRequestImage();
  vpRequestImage(vpImage<unsigned char> *);
  ~vpRequestImage();

  virtual void encode();
  virtual void decode();
};

/* end vpRequestImage.h */

/* begin vpRequestImage.cpp */
//#include "vpRequestImage.h"

vpRequestImage::vpRequestImage()
{
  request_id = "image";
}

vpRequestImage::vpRequestImage(vpImage<unsigned char> *Im)
{
  request_id = "image";
  I = Im;
}

vpRequestImage::~vpRequestImage() { }

void vpRequestImage::encode()
{
  clear();

  unsigned int h = I->getHeight();
  unsigned int w = I->getWidth();

  addParameterObject(&h);
  addParameterObject(&w);
  addParameterObject(I->bitmap, h*w*sizeof(unsigned char));
}

void vpRequestImage::decode()
{
  if (listOfParams.size() == 3) {
    unsigned int w, h;
    memcpy((void *)&h, (void *)listOfParams[0].c_str(), sizeof(unsigned int));
    memcpy((void *)&w, (void *)listOfParams[1].c_str(), sizeof(unsigned int));

    I->resize(h, w);
    memcpy((void *)I->bitmap, (void *)listOfParams[2].c_str(), w*h*sizeof(unsigned char));
  }
}

/* end vpRequestImage.cpp */

int main(int argc, char **argv)
{
#if defined(VISP_HAVE_V4L2)
  std::string servername = "localhost";
  unsigned int port = 35000;

  vpImage<unsigned char> I; // Create a gray level image container

  // Create a grabber based on v4l2 third party lib (for usb cameras under Linux)
  vpV4l2Grabber g;
  g.setDevice("/dev/video1");
  //g.setScale(1);
  //g.setInput(0);
  g.open(I);

  // Create an image viewer
#ifdef VISP_HAVE_X11
  vpDisplayX d(I, -1, -1, "Camera frame");
#elif defined VISP_HAVE_GDI //Win32
  vpDisplayGDI d(I, -1, -1, "Camera frame");
#endif

  vpClient client;
  client.connectToHostname(servername, port);
  //client.connectToIP("127.0.0.1",port);

  vpRequestImage reqImage(&I);

  while (1) {
    double t = vpTime::measureTimeMs();
    // Acquire a new image
    g.acquire(I);

    vpDisplay::display(I);
    vpDisplay::flush(I);

    client.sendAndEncodeRequest(reqImage);

    // A click in the viewer to exit
    if (vpDisplay::getClick(I, false))
      break;
  }

  return 0;
#endif
}
