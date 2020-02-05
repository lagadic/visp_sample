#include <iostream>

#include <visp3/core/vpImage.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/sensor/vp1394CMUGrabber.h>

int main()
{
#if defined(VISP_HAVE_CMU1394)
  std::cout << "ViSP Image acquisition example" << std::endl;

  vpImage<unsigned char> I;
  vp1394CMUGrabber g;

  if( g.getNumberOfConnectedCameras() > 1 )
    std::cout << "There are " << g.getNumberOfConnectedCameras() << " connected cameras." << std::endl;
  if( g.getNumberOfConnectedCameras() == 1 )
    std::cout << "There is " << g.getNumberOfConnectedCameras() << " connected camera." << std::endl;
  else
    std::cout << "There is no connected camera." << std::endl;

  // Setting camera parameters manually
  g.selectCamera(0);
  g.setControl(0, 2000);
  g.setFPS(3);          // 15 FPS
  g.setVideoMode(0, 5); // 640x480 - MONO

  g.open(I);
  g.acquire(I);

  // Display camera description
  g.displayCameraDescription(0);
  g.displayCameraModel();
  std::cout << "Height: " << g.getHeight() << " Width: " << g.getWidth() << std::endl;

  vpDisplayOpenCV d(I);
  vpDisplay::display(I);

  for(;;)
  {
    g.acquire(I);
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false)) // a click to exit
        break;
  }

  g.close();
#endif
  std::cout << "ViSP exiting..." <<std::endl;
  return 0;
}
