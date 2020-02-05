#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  int nframes = 100;
  vpImage<unsigned char> I;
  vpFlyCaptureGrabber g;

  g.setCameraIndex(0); // Default camera is the first on the bus
  g.getCameraInfo(std::cout);
  g.setVideoModeAndFrameRate(FlyCapture2::VIDEOMODE_1280x960Y8, FlyCapture2::FRAMERATE_60);
  g.open(I);

  for(int i=0; i< nframes; i++) {
    g.acquire(I);
  }
#endif
}

