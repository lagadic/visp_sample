#include <visp3/core/vpImage.h>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  int nframes = 100;
  vpImage<unsigned char> I;
  vpFlyCaptureGrabber g;

  g.connect();
  FlyCapture2::Camera *handler = g.getCameraHandler();
  bool supported = false;
  handler->GetVideoModeAndFrameRateInfo(FlyCapture2::VIDEOMODE_1280x960Y8, FlyCapture2::FRAMERATE_60, &supported);
  if (supported)
    g.setVideoModeAndFrameRate(FlyCapture2::VIDEOMODE_1280x960Y8, FlyCapture2::FRAMERATE_60);
  g.startCapture();

  for(int i=0; i< nframes; i++) {
    g.acquire(I);
  }
#endif
}

