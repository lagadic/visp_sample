#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/me/vpMeNurbs.h>
#include <visp3/core/vpImagePoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> I(240, 320);

  // Fill the image with a black rectangle
  I = 0;
  for (int i = 100; i < 180; i++) {
    for (int j = 0; j < 320; j++) {
      I[i][j] = 255;
    }
  }

  // Set the moving-edges tracker parameters
  vpMe me;
  me.setRange(25);
  me.setPointsToTrack(20);
  me.setThreshold(15000);
  me.setSampleStep(10);

  // Initialize the moving-edges tracker parameters
  vpMeNurbs meNurbs;
  meNurbs.setNbControlPoints(4);
  meNurbs.setMe(&me);

  // Initialize the location of the edge to track (here a horizontal line
  std::list<vpImagePoint> ipList; //List of points belonginig to the edge
  ipList.push_back(vpImagePoint(110, 119));
  ipList.push_back(vpImagePoint(140, 119));
  ipList.push_back(vpImagePoint(160, 119));
  ipList.push_back(vpImagePoint(170, 119));

  meNurbs.initTracking(I, ipList);

  for (; ; ) {
    // ... Here the code to read or grab the next image.

    // Track the line.
    meNurbs.track(I);
  }
  return 0;
}
