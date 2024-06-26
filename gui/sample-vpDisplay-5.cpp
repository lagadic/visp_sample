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
  vpImage<vpRGBa> I(240, 320); // Create a black RGB color image

  vpDisplay *d;

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
#else
  std::cout << "Sorry, no video device is available" << std::endl;
  return -1;
#endif

  // Initialize the display with the image I. Display and image are
  // now link together.
#ifdef VISP_HAVE_DISPLAY
  d->init(I);
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

#ifdef VISP_HAVE_DISPLAY
  delete d;
#endif
}
