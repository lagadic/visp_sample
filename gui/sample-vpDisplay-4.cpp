#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpDisplayFactory.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> I(240, 320); // Create a black image

#if defined(VISP_HAVE_DISPLAY)
  // If a GUI library is available, create a display and
  // initialize the display with the image I. Display and image are
  // now link together.
  // Otherwise, return nullptr or an unitialized shared_ptr.
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display = vpDisplayFactory::createDisplay(I);
#else
  vpDisplay *display = vpDisplayFactory::allocateDisplay(I);
#endif
#else
  std::cout << "Sorry, no video device is available" << std::endl;
  return -1;
#endif

  // Set the display background with image I content
  vpDisplay::display(I);

  // Flush the foreground and background display
  vpDisplay::flush(I);

  // Wait for keyboard event
  std::cout << "Waiting a keyboard event..." << std::endl;
  vpDisplay::getKeyboardEvent(I, true);
  std::cout << "A keyboard event was detected" << std::endl;

  // Non blocking keyboard event loop
  int cpt_event = 0;
  bool event;
  char key[10];
  std::cout << "Enter a non blocking keyboard event detection loop..." << std::endl;
  do {
    event = vpDisplay::getKeyboardEvent(I, &key[0], false);
    if (event) {
      std::cout << "Key detected: " << key << std::endl;
      cpt_event++;
    }

    vpTime::wait(5); // wait 5 ms
  } while (cpt_event < 5);

#if defined(VISP_HAVE_DISPLAY) && (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
}
