#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vpOpenCVGrabber.h>

int main()
{
#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION < 0x020408)
  vpImage<unsigned char> I; // Create a gray level image container
  vpOpenCVGrabber g;        // Create a grabber based on OpenCV third party lib

  g.open(I);                           // Open the framegrabber
  g.acquire(I);                        // Acquire an image
  vpImageIo::writePGM(I, "image.pgm"); // Write image on the disk
#endif
}
