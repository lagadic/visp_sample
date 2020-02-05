#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  vpImage<unsigned char> I; // Create a gray level image container
  bool reset = false; // Disable bus reset during construction
  vp1394TwoGrabber g(reset); // Create a grabber based on libdc1394-2.x third party lib

  unsigned int ncameras; // Number of cameras on the bus
  ncameras = g.getNumCameras();
  std::cout << ncameras << " cameras found:" << std::endl;

  for(unsigned int i=0; i< ncameras; i++)
  {
    g.setCamera(i);
    uint64_t guid = g.getGuid();
    printf("camera %d with guid 0x%lx\n", i, (long unsigned int)guid);
  }

  // produce:
  // 2 cameras found:
  // camera 0 with guid 0xb09d01009b329c
  // camera 1 with guid 0xb09d01007e0ee7
  g.setCamera( (uint64_t)0xb09d01009b329cULL );

  printf("Use camera with GUID: 0x%lx\n", (long unsigned int)g.getGuid());
  g.acquire(I); // Acquire an image from the camera with GUID 0xb09d01009b329c

  vpImageIo::writePGM(I, "image.pgm"); // Write image on the disk
#endif
}
