#include <visp3/core/vpConfig.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/gui/vpDisplayFactory.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_DISPLAY

#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  std::shared_ptr<vpDisplay> display;
#else
  vpDisplay *display = nullptr;
#endif
  try {
    vpImage<unsigned char> I; // Grey level image

    // Read an image in PGM P5 format
#ifdef _WIN32
    std::string filename("C:/temp/ViSP-images/Klimt/Klimt.ppm");
#else
    std::string filename("/local/soft/ViSP/ViSP-images/Klimt/Klimt.ppm");
#endif

    vpImageIo::read(I, filename);

    // Depending on the detected third party libraries, we instantiate here the
    // first video device which is available
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
    display = vpDisplayFactory::createDisplay();
#else
    display = vpDisplayFactory::allocateDisplay();
#endif

    // Initialize the display with the image I. Display and image are
    // now link together.
    display->init(I);

    // Specify the window location
    vpDisplay::setWindowPosition(I, 400, 100);

    // Set the display window title
    vpDisplay::setTitle(I, "My image");

    // To initialize the video device, it is also possible to replace
    // the 3 previous lines by:
    // d->init(I, 400, 100, "My image");

    // Set the display background with image I content
    vpDisplay::display(I);

    // Draw a red rectangle in the display overlay (foreground)
    vpDisplay::displayRectangle(I, 10, 10, 100, 20, vpColor::red, true);

    // Draw a red rectangle in the display overlay (foreground)
    vpImagePoint topLeftCorner;
    topLeftCorner.set_i(50);
    topLeftCorner.set_j(10);
    vpDisplay::displayRectangle(I, topLeftCorner, 100, 20, vpColor::green, true);

    // Flush the foreground and background display
    vpDisplay::flush(I);

    // Get non blocking keyboard events
    std::cout << "Check keyboard events..." << std::endl;
    char key[10];
    bool ret;
    for (int i = 0; i < 200; i++) {
      bool ret = vpDisplay::getKeyboardEvent(I, key, false);
      if (ret)
        std::cout << "keyboard event: key: " << "\"" << key << "\"" << std::endl;
      vpTime::wait(40);
    }

    // Get a blocking keyboard event
    std::cout << "Wait for a keyboard event..." << std::endl;
    ret = vpDisplay::getKeyboardEvent(I, key, true);
    std::cout << "keyboard event: " << ret << std::endl;
    if (ret)
      std::cout << "key: " << "\"" << key << "\"" << std::endl;

  // Wait for a click in the display window
    std::cout << "Wait for a button click..." << std::endl;
    vpDisplay::getClick(I);
  }
  catch (...) { }
#if (VISP_CXX_STANDARD < VISP_CXX_STANDARD_11)
  if (display != nullptr) {
    delete display;
  }
#endif
#endif
}
