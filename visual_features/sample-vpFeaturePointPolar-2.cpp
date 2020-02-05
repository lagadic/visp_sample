#include <visp3/visual_features/vpFeaturePointPolar.h>
#include <visp3/core/vpMatrix.h>

int main()
{
  // Creation of the current feature s
  vpFeaturePointPolar s;
  // Initialize the current feature
  s.buildFrom(0.1, M_PI, 1); // rho=0.1m, theta=pi, Z=1m

  // Creation of the desired feature s
  vpFeaturePointPolar s_star;
  // Initialize the desired feature
  s.buildFrom(0.15, 0, 0.8); // rho=0.15m, theta=0, Z=0.8m

  // Compute the interaction matrix L_s for the current feature
  vpMatrix L = s.interaction();

  // Compute the error vector (s-s*) for the point feature with polar coordinates
  s.error(s_star);

  return 0;
}
