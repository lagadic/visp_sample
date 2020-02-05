#include <visp3/core/vpImage.h>
#include <visp3/me/vpMeLine.h>

int main()
{
  vpImage<unsigned char> I(240, 320);

  // Fill the image with a black rectangle
  I = 0;
  for (int i = 100; i < 180; i ++) {
    for (int j = 120; j < 250; j ++) {
      I[i][j] = 255;
    }
  }

  // Set the moving-edges tracker parameters
  vpMe me;
  me.setRange(25);
  me.setPointsToTrack(20);
  me.setThreshold(15000);
  me.setSampleStep(10);

  // Initialize the moving-edges line tracker parameters
  vpMeLine line;
  line.setMe(&me);

  // Initialize the location of the vertical line to track
  vpImagePoint ip1, ip2; // Two points belonging to the line to track
  ip1.set_i( 120 );
  ip1.set_j( 119 );
  ip2.set_i( 170 );
  ip2.set_j( 122 );

  line.initTracking(I, ip1, ip2);

  for ( ; ; )
  {
    // ... Here the code to read or grab the next image.

    // Track the line.
    line.track(I);
  }
  return 0;
}
