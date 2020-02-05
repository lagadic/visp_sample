#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    bool reset = false; // Disable bus reset during construction
    vp1394TwoGrabber g(reset);    // Creation of a grabber instance based on libdc1394-2.x third party lib.
    unsigned int ncameras; // Number of cameras on the bus
    ncameras = g.getNumCameras();

    // Create an image container for each camera
    vpImage<unsigned char> *I = new vpImage<unsigned char> [ncameras];
    char filename[FILENAME_MAX];

    // If the first camera supports vpVIDEO_MODE_640x480_YUV422 video mode
    g.setCamera(0);
    g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_640x480_YUV422);

    // If the second camera support 30 fps acquisition
    g.setCamera(1);
    g.setFramerate(vp1394TwoGrabber::vpFRAMERATE_30);

    // Acquire an image from each camera
    for (unsigned int camera=0; camera < ncameras; camera ++) {
      g.setCamera(camera);
      g.acquire(I[camera]);
      sprintf(filename, "image-cam%d.pgm", camera);
      vpImageIo::writePGM(I[camera], filename);
    }
    delete [] I;
  }
  catch(...) {}
#endif
}
