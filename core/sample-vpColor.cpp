#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> I(240, 320); // Create a black grey level image

  // A new display will be instantiated if a GUI library is available
  // ohterwise we will have nullptr or a uninitialized shared pointer.
  // If the creation is successful, the display and image are
  // now link together.
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I);
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I);
#endif

  // Set the display background with image I content
  vpDisplay::display(I);

  // Draw a filled circle with the predefined blue color
  vpDisplay::displayCircle(I, 100, 200, 30, vpColor::blue, true);

  // Creation of a new brown color with its RGB values
  vpColor color(128, 100, 50);

  // Draw a brown rectangle in the display overlay (foreground)
  vpDisplay::displayRectangle(I, 10, 10, 100, 20, color, true);

  // Flush the foreground and background display
  vpDisplay::flush(I);

#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
}
