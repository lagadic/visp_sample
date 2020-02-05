#include <visp3/visual_features/vpFeatureThetaU.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpMatrix.h>

int main()
{
  vpHomogeneousMatrix cdMc;
  // ... cdMc need here to be initialized from for example a pose estimation.

  // Creation of the current feature s
  vpFeatureThetaU s(vpFeatureThetaU::cdRc);
  s.buildFrom(cdMc); // Initialization of the feature

  // Creation of the desired feature s*. By default this feature is 
  // initialized to zero
  vpFeatureThetaU s_star(vpFeatureThetaU::cdRc); 

  // Compute the interaction matrix L_s for the current ThetaU feature
  vpMatrix L = s.interaction();

  // Compute the error vector (s-s*) for the ThetaU feature
  vpColVector e = s.error(s_star); // e = (s-s*)
}
