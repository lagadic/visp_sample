#include <visp3/core/vpConfig.h>
#include <visp3/gui/vpPlot.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_DISPLAY)
  // Create a window (700 by 700) at position (100, 200) with two graphics
  vpPlot A(2, 700, 700, 100, 200, "Curves...");

  // The first graphic contains 1 curve and the second graphic contains 2 curves
  A.initGraph(0, 1);
  A.initGraph(1, 2);

  // The color of the curve in the first graphic is red
  A.setColor(0, 0, vpColor::red);
  // The first curve in the second graphic is green
  A.setColor(1, 0, vpColor::green);
  // The second curve in the second graphic is blue
  A.setColor(1, 1, vpColor::blue);

  // Add the point (0,0) in the first graphic
  A.plot(0, 0, 0, 0);

  // Add the point (0,1) to the first curve of the second graphic
  A.plot(1, 0, 0, 1);

  // Add the point (0,2) to the second curve of the second graphic
  A.plot(1, 1, 0, 2);

  for (int i = 0; i < 50; i++) {
    // Add the point (i,sin(i*pi/10) in the first graphic
    A.plot(0, 0, i, sin(i*M_PI/10));

    // Add the point (i,1) to the first curve of the second graphic
    A.plot(1, 0, i, 1);

    // Add the point (i,2) to the second curve of the second graphic
    A.plot(1, 1, i, 2);
  }

  return 0;
#endif
}
