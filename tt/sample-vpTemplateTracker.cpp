#include <visp3/tt/vpTemplateTrackerSSDInverseCompositional.h>
#include <visp3/tt/vpTemplateTrackerWarpHomography.h>

int main()
{
  vpImage<unsigned char> I;
  vpTemplateTrackerWarpHomography warp;
  vpTemplateTrackerSSDInverseCompositional tracker(&warp);
  vpTemplateTrackerZone zoneRef, zoneWarped;

  // Display the warped zone
  tracker.display(I, vpColor::red);

  // Display the reference zone
  zoneRef = tracker.getZoneRef();
  zoneRef.display(I, vpColor::green);

  // Display the warped zone
  vpColVector p = tracker.getp();
  warp.warpZone(zoneRef, p, zoneWarped);
  zoneWarped.display(I, vpColor::blue);
}
