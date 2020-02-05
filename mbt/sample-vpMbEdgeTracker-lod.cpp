#include <visp3/io/vpImageIo.h>
#include <visp3/mbt/vpMbEdgeTracker.h>

int main()
{
  vpImage<unsigned char> I;

  // Acquire an image
  vpImageIo::read(I, "my-image.pgm");

  std::string object = "my-object";
  vpMbEdgeTracker tracker;
  tracker.loadConfigFile( object+".xml" );
  tracker.loadModel( object+".cao" );

  tracker.setLod(true);
  tracker.setMinLineLengthThresh(20.);
  tracker.setMinPolygonAreaThresh(20.*20.);

  tracker.initClick(I, object+".init" );

  while (true) {
    // tracking loop
  }
}
