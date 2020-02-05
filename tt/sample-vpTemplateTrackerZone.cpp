#include <visp3/tt/vpTemplateTrackerZone.h>

int main()
{
  vpTemplateTrackerZone zone;
  for (unsigned int i=0; i < zone.getNbTriangle(); i++) {
    vpTemplateTrackerTriangle triangle;
    zone.getTriangle(i, triangle);
  }

  for (unsigned int i=0; i < zone.getNbTriangle(); i++) {
    vpTemplateTrackerTriangle triangle = zone.getTriangle(i);
  }
}
