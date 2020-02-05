#include <visp3/io/vpVideoWriter.h>

int main()
{
  vpImage<vpRGBa> I;

  vpVideoWriter writer;

  // Set up the framerate to 30Hz. Default is 25Hz.
  writer.setFramerate(30);

#if VISP_HAVE_OPENCV_VERSION >= 0x030000
  writer.setCodec( cv::VideoWriter::fourcc('P','I','M','1') );
#elif VISP_HAVE_OPENCV_VERSION >= 0x020100
  writer.setCodec( CV_FOURCC('P','I','M','1') );
#endif

  writer.setFileName("./test.mpeg");

  writer.open(I);

  for ( ; ; )
  {
    // Here the code to capture or create an image and store it in I.

    // Save the image
    writer.saveFrame(I);
  }

  writer.close();

  return 0;
}
