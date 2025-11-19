#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_DISPLAY
  vpImage<unsigned char> I;
  vpImageIo::read(I, "Klimt.pgm");

  // If a GUI library is available, create a display.
  // Otherwise, return nullptr or an unitialized shared_ptr.
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay();
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay();
#endif

  display->init(I.getWidth(), I.getHeight(), 10, 20, "viewer");

  // Now associate the display to the image
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  I.display = display.get();
#else
  I.display = display;
#endif

// Set the display background with image I content
  vpDisplay::display(I);

  // Flush the foreground and background display
  vpDisplay::flush(I);

  // wait for a mouse clink in the display to exit
  vpDisplay::getClick(I);

#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
#endif
}
