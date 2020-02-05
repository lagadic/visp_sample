#include <visp3/core/vpLinearKalmanFilterInstantiation.h>

int main()
{
  vpLinearKalmanFilterInstantiation kalman;

  kalman.setStateModel(vpLinearKalmanFilterInstantiation::stateConstVelWithColoredNoise_MeasureVel);
  std::cout << "State vector size: " << kalman.getStateSize() << std::endl; // Value is 2
  std::cout << "Measure vector size: " << kalman.getMeasureSize() << std::endl; // Value is 1
}  
