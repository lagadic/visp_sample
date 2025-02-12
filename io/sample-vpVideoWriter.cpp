#include <visp3/core/vpConfig.h>
#include <visp3/io/vpVideoWriter.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && defined(HAVE_OPENCV_VIDEOIO) && defined(HAVE_OPENCV_HIGHGUI)
  vpImage<vpRGBa> I;

  vpVideoWriter writer;

  // Set up the framerate to 30Hz. Default is 25Hz.
  writer.setFramerate(30);

#if VISP_HAVE_OPENCV_VERSION >= 0x030000
  writer.setCodec(cv::VideoWriter::fourcc('P', 'I', 'M', '1'));
#else
  writer.setCodec(CV_FOURCC('P', 'I', 'M', '1'));
#endif

  writer.setFileName("./test.mpeg");

  writer.open(I);

  for (; ; ) {
    // Here the code to capture or create an image and store it in I.

    // Save the image
    writer.saveFrame(I);
  }

  writer.close();
#endif
  return 0;
}
