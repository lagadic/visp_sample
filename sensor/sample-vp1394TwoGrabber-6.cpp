#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    vp1394TwoGrabber g;
    dc1394video_frame_t *frame;
    g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_640x480_MONO8);
    g.setFramerate(vp1394TwoGrabber::vpFRAMERATE_15);
    for (int i = 0; i<10; i++) {
      frame = g.dequeue();
      // Current image is now in frame structure
      // Do your stuff
      g.enqueue(frame);
    }
  }
  catch (...) { }
#endif
}
