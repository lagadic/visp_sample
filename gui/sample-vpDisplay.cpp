#include <visp3/io/vpImageIo.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/gui/vpDisplayGTK.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayD3D.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  try {
    vpImage<unsigned char> I; // Grey level image

    // Read an image in PGM P5 format
#ifdef _WIN32
    std::string filename("C:/temp/ViSP-images/Klimt/Klimt.ppm");
#else
    std::string filename("/local/soft/ViSP/ViSP-images/Klimt/Klimt.ppm");
#endif

    vpDisplay *d;

    // Depending on the detected third party libraries, we instantiate here the
    // first video device which is available
#if defined(VISP_HAVE_X11)
    d = new vpDisplayX;
#elif defined(VISP_HAVE_GTK)
    d = new vpDisplayGTK;
#elif defined(VISP_HAVE_GDI)
    d = new vpDisplayGDI;
#elif defined(VISP_HAVE_D3D9)
    d = new vpDisplayD3D;
#elif defined(HAVE_OPENCV_HIGHGUI)
    d = new vpDisplayOpenCV;
#endif

        // Initialize the display with the image I. Display and image are
        // now link together.
#ifdef VISP_HAVE_DISPLAY
    d->init(I);
#endif

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

#ifdef VISP_HAVE_DISPLAY
    delete d;
#endif
  }
  catch (...) { }
}
