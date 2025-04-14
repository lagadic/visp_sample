#include <visp3/core/vpConfig.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/gui/vpDisplayD3D.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_D3D9)
  vpImage<unsigned char> I; // Grey level image

  // Read an image in PGM P5 format
  vpImageIo::readPGM(I, "C:/temp/ViSP-images/Klimt/Klimt.pgm");

  vpDisplayD3D d;

  // Initialize the display with the image I. Display and image are
  // now link together.
  d.init(I);

  // Set the display window title
  vpDisplay::setTitle(I, "My Direct 3D display");

  // Set the display background with image I content
  vpDisplay::display(I);

  // Draw a red rectangle in the display overlay (foreground)
  vpDisplay::displayRectangle(I, 10, 10, 100, 20, vpColor::red);

  // Flush the foreground and background display
  vpDisplay::flush(I);

  // Wait for a click in the display window
  vpDisplay::getClick(I);
#endif
}
