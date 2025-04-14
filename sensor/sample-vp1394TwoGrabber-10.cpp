#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  try {
    vpImage<vpRGBa> I;
    vp1394TwoGrabber g;
    dc1394video_frame_t *frame;
    uint64_t timestamp_us; // timestamp in us
    uint32_t id;
    g.setVideoMode(vp1394TwoGrabber::vpVIDEO_MODE_640x480_MONO8);
    g.setFramerate(vp1394TwoGrabber::vpFRAMERATE_15);
    for (int i = 0; i<10; i++) {
      frame = g.dequeue(I, timestamp_us, id); // get the last image
      // Current image is now in frame structure and in I
      // Do your stuff
      g.enqueue(frame);
    }
  }
  catch (...) { }
#endif
}
