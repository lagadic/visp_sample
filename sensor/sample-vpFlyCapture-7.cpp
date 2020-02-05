#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  int nframes = 100;
  vpImage<unsigned char> I;
  vpFlyCaptureGrabber g;

  g.setCameraSerial(15290004); // Set camera with serial id
  g.open(I);
  g.getCameraInfo(std::cout);

  for(int i=0; i< nframes; i++) {
    g.acquire(I);
  }
#endif
}

