#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  int nframes = 100;
  char filename[255];
  unsigned int numCameras = vpFlyCaptureGrabber::getNumCameras();

  std::cout << "Number of cameras detected: " << numCameras << std::endl;

  vpFlyCaptureGrabber *g = new vpFlyCaptureGrabber [numCameras];
  std::vector< vpImage<unsigned char> > I(numCameras);

  for(unsigned int cam=0; cam < numCameras; cam++) {
    g[cam].setCameraIndex(cam); // Default camera is the first on the bus
    g[cam].getCameraInfo(std::cout);
    g[cam].open(I[cam]);
  }

  for(int i=0; i< nframes; i++) {
    for(unsigned int cam=0; cam < numCameras; cam++) {
      g[cam].acquire(I[cam]);
      sprintf(filename, "image-camera%d-%04d.pgm", cam, i);
      vpImageIo::write(I[cam], filename);
    }
  }
  delete [] g;
#endif
}

