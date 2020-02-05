#include <iomanip>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  int nframes = 100;
  vpImage<unsigned char> I;
  char filename[255];
  vpFlyCaptureGrabber g;
  std::cout << "Number of cameras detected: " << g.getNumCameras() << std::endl;

  g.setCameraIndex(0); // Default camera is the first on the bus

  float framerate = g.getFrameRate();
  std::cout << "Cur frame rate: " << std::fixed << std::setprecision(3) << framerate << " fps" << std::endl;
  framerate = g.setFrameRate(30); // Set framerate to 30 fps
  std::cout << "New frame rate: " << std::fixed << std::setprecision(3) << framerate << " fps" << std::endl;

  float shutter_ms = g.getShutter();
  std::cout << "Shutter       : " << shutter_ms << " ms" << std::endl;
  shutter_ms = g.setShutter(false, 10); // Turn manual shutter on to 10ms
  std::cout << "Shutter manual: " << shutter_ms << " ms" << std::endl;
  shutter_ms = g.setShutter(true); // Turn auto shutter on
  std::cout << "Shutter auto  : " << shutter_ms << " ms" << std::endl;

  float gain_db = g.getGain();
  std::cout << "Gain       : " << gain_db << " db" << std::endl;
  gain_db = g.setGain(false, 5); // Turn manual gain on to 5db
  std::cout << "Gain manual: " << gain_db << " db" << std::endl;
  gain_db = g.setGain(true); // Turn auto shutter on
  std::cout << "Gain auto  : " << gain_db << " db" << std::endl;

  float brightness = g.getBrightness();
  std::cout << "Brightness       : " << brightness << " %" << std::endl;
  brightness = g.setBrightness(false, 2); // Turn manual brightness on to 2%
  std::cout << "Brightness manual: " << brightness << " %" << std::endl;
  brightness = g.setBrightness(true); // Turn auto brightness on
  std::cout << "Brightness auto  : " << brightness << " %" << std::endl;

  float exposure = g.getExposure();
  std::cout << "Exposure       : " << exposure << std::endl;
  exposure = g.setExposure(true, false, 1); // Turn manual exposure on to 1
  std::cout << "Exposure manual: " << exposure << std::endl;
  exposure = g.setExposure(true, true); // Turn auto exposure on
  std::cout << "Exposure auto  : " << exposure << std::endl;

  float sharpness = g.getSharpness();
  std::cout << "Sharpness       : " << sharpness << std::endl;
  sharpness = g.setSharpness(true, false, 1000); // Turn manual sharpness on to 1000
  std::cout << "Sharpness manual: " << sharpness << std::endl;
  sharpness = g.setSharpness(true, true); // Turn auto sharpness on
  std::cout << "Sharpness auto  : " << sharpness << std::endl;

  g.getCameraInfo(std::cout);
  g.open(I);

  for(int i=0; i< nframes; i++) {
    g.acquire(I);
    sprintf(filename, "image%04d.pgm", i);
    vpImageIo::write(I, filename);
  }
#endif
}

