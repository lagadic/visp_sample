#include <visp3/visual_features/vpFeatureTranslation.h>
#include <visp3/core/vpHomogeneousMatrix.h>
#include <visp3/core/vpMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpHomogeneousMatrix cdMc;
  // ... cdMc need here to be initialized from for example a pose estimation.

  // Creation of the current feature s
  vpFeatureTranslation s(vpFeatureTranslation::cdMc);
  s.buildFrom(cdMc); // Initialization of the feature

  // Creation of the desired feature s*. By default this feature is
  // initialized to zero
  vpFeatureTranslation s_star(vpFeatureTranslation::cdMc);

  // Compute the interaction matrix for the translation feature
  vpMatrix L = s.interaction();

  // Compute the error vector (s-s*) for the translation feature
  vpColVector e = s.error(s_star); // e = (s-s*)
}
