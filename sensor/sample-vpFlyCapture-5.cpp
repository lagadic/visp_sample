#include <visp3/sensor/vpFlyCaptureGrabber.h>

int main()
{
#if defined(VISP_HAVE_FLYCAPTURE)
  vpFlyCaptureGrabber g;
  g.connect();
  FlyCapture2::Camera *handler = g.getCameraHandler();

  // Query for available Format 7 modes
  const FlyCapture2::Mode k_fmt7Mode = FlyCapture2::MODE_0;
  const FlyCapture2::PixelFormat k_fmt7PixFmt = FlyCapture2::PIXEL_FORMAT_MONO8;

  FlyCapture2::Format7Info fmt7Info;
  bool supported;
  fmt7Info.mode = k_fmt7Mode;
  FlyCapture2::Error error = handler->GetFormat7Info( &fmt7Info, &supported );
  if (error != FlyCapture2::PGRERROR_OK) {
    error.PrintErrorTrace();
    return -1;
  }
  if (supported) {
    std::cout << "Max image pixels: (" << fmt7Info.maxWidth << ", " << fmt7Info.maxHeight << ")" << std::endl;
    std::cout << "Image Unit size: (" << fmt7Info.imageHStepSize << ", " << fmt7Info.imageVStepSize << ")" << std::endl;
    std::cout << "Offset Unit size: (" << fmt7Info.offsetHStepSize << ", " << fmt7Info.offsetVStepSize << ")" << std::endl;
    std::cout << "Pixel format bitfield: 0x" << fmt7Info.pixelFormatBitField << std::endl;

    if ( (k_fmt7PixFmt & fmt7Info.pixelFormatBitField) == 0 ) {
      // Pixel format not supported!
      std::cout << "Pixel format is not supported" << std::endl;
      return -1;
    }
  }
#endif
}

