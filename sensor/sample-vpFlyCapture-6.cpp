#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  vpFlyCaptureGrabber g;
  unsigned int num_cameras = vpFlyCaptureGrabber::getNumCameras();
  for (unsigned int i=0; i<num_cameras; i++) {
    unsigned int serial_id = vpFlyCaptureGrabber::getCameraSerial(i);
    std::cout << "Camera with index " << i << " has serial id: " << serial_id << std::endl;
  }
#endif
}

