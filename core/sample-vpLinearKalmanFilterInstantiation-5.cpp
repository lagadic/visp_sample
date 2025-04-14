#include <visp3/core/vpConfig.h>
#include <visp3/core/vpLinearKalmanFilterInstantiation.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpLinearKalmanFilterInstantiation kalman;

  kalman.setStateModel(vpLinearKalmanFilterInstantiation::stateConstVelWithColoredNoise_MeasureVel);
  std::cout << "State vector size: " << kalman.getStateSize() << std::endl; // Value is 2
  std::cout << "Measure vector size: " << kalman.getMeasureSize() << std::endl; // Value is 1
}
