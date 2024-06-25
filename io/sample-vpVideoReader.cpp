#include <visp3/io/vpVideoReader.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_FFMPEG
  vpImage<vpRGBa> I;

  vpVideoReader reader;

  // Initialize the reader.
  reader.setFileName("video.mpeg");
  reader.open(I);

  // Read the nearest key frame from the 3th frame
  reader.getFrame(I, 2);

  // After positionning the video reader use acquire to read the video frame by frame
  reader.acquire(I);

  return 0;
#endif
}
