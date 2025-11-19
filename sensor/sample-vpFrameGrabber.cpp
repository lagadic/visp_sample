#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/sensor/vpV4l2Grabber.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_V4L2) || defined(VISP_HAVE_DC1394_2)
  vpImage<unsigned char> I;
  vpFrameGrabber *g; // Generic framegrabber

#if defined( VISP_HAVE_DC1394_2 )
  vp1394TwoGrabber *g_1394_2 = new vp1394TwoGrabber;
  // specific settings for firewire grabber based on libdc1394-2.x version
  g_1394_2->setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_320x240_YUV422);
  g_1394_2->setFramerate(vp1394TwoGrabber::vpFRAMERATE_30);
  g = g_1394_2;
#elif defined( VISP_HAVE_V4L2 )
  vpV4l2Grabber *g_v4l2 = new vpV4l2Grabber;
  // specific settings for Video For Linux Two grabber
  g_v4l2->setInput(2);    // Input 2 on the board
  g_v4l2->setFramerate(vpV4l2Grabber::framerate_50fps); // 50 fps
  g_v4l2->setWidth(384);  // Acquired images are 768 width
  g_v4l2->setHeight(288); // Acquired images are 576 height
  g_v4l2->setNBuffers(3); // 3 ring buffers to ensure real-time acquisition
  g = g_v4l2;
#endif

  g->open(I);                           // Open the framegrabber
  g->acquire(I);                        // Acquire an image
  vpImageIo::writePGM(I, "image.pgm");  // Write image on the disk
#endif
}
