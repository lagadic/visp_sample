#include <iomanip>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  vpImage<unsigned char> I;

  vpFlyCaptureGrabber g;
  g.setCameraIndex(0);
  float framerate = 20;
  g.setFrameRate(framerate); // Set framerate to 20 fps
  std::cout << "Frame rate: " << std::fixed << std::setprecision(3) << framerate << " fps" << std::endl;
  std::cout << "Frame rate: " << std::fixed << std::setprecision(3) << g.getFrameRate() << " fps" << std::endl;

  g.open(I);
  //while (1)
    for(int i=0; i<10; i++)
    g.acquire(I);
#endif
}
