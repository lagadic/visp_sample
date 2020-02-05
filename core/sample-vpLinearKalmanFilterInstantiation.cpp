#include <visp3/core/vpLinearKalmanFilterInstantiation.h>

int main()
{
  vpLinearKalmanFilterInstantiation kalman;
  // Select a constant velocity state model with colored noise
  // Measures are velocities
  kalman.setStateModel(vpLinearKalmanFilterInstantiation::stateConstVelWithColoredNoise_MeasureVel);

  // Initialise the filter for a one dimension signal
  int signal = 1;
  vpColVector sigma_state(2);   // State vector size is 2
  vpColVector sigma_measure(1); // Measure vector size is 1
  double rho = 0.9;
  double dummy = 0; // non used parameter for the selected state model

  kalman.initFilter(signal, sigma_state, sigma_measure, rho, dummy);
}
