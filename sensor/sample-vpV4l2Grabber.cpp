#include <visp3/sensor/vpV4l2Grabber.h>
#include <visp3/io/vpImageIo.h>

int main()
{
#if defined(VISP_HAVE_V4L2)
  vpImage<unsigned char> I;
  vpV4l2Grabber g;
  g.setInput(2);    // Input 2 on the board
  g.setFramerate(vpV4l2Grabber::framerate_25fps); //  25 fps
  g.setWidth(768);  // Acquired images are 768 width
  g.setHeight(576); // Acquired images are 576 height
  g.setNBuffers(3); // 3 ring buffers to ensure real-time acquisition
  g.open(I);        // Open the grabber

  g.acquire(I);     // Acquire a 768x576 grey image
  vpImageIo::writePGM(I, "image.pgm"); // Save the image on the disk
#endif
}
