#include <visp3/core/vpImage.h>
#include <visp3/sensor/vpKinect.h>

int main() {
#ifdef VISP_HAVE_LIBFREENECT_AND_DEPENDENCIES
  // Init Kinect device
#ifdef VISP_HAVE_LIBFREENECT_OLD
  // This is the way to initialize Freenect with an old version of libfreenect
  // package under ubuntu lucid 10.04
  Freenect::Freenect<vpKinect> freenect;
  vpKinect * kinect = &freenect.createDevice(0);
#else
  Freenect::Freenect freenect;
  vpKinect * kinect = &freenect.createDevice<vpKinect>(0);
#endif
  kinect->start(); // Start acquisition thread

  // Set tilt angle
  float angle = -5;
  kinect->setTiltDegrees(angle);

  vpImage<unsigned char> I(480,640);
  vpImage<vpRGBa> Irgb(480,640);
  vpImage<float> dmap(480,640);

  // Acquisition loop
  for (int i=0; i<100; i++)
  {
    kinect->getDepthMap(dmap,I);
    kinect->getRGB(Irgb);
  }
  std::cout << "Stop acquisition" << std::endl;
  kinect->stop(); // Stop acquisition thread
#endif
  return 0;
}

