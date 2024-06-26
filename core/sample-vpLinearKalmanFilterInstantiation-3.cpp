#include <visp3/core/vpLinearKalmanFilterInstantiation.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpLinearKalmanFilterInstantiation kalman;
  // Filter the x and y velocities of a target (2 signals are to consider)
  int nsignal = 2;

  // Initialize the filter parameters:
  // - Firstly, the state variance
  vpColVector sigma_state(6); // 6 = 3 for the state size x 2 signal
  sigma_state[1] = 0.001; // Variance on the acceleration for the 1st signal (x)
  sigma_state[2] = 0.001; // Variance on the acceleration for the 1st signal (x)
  sigma_state[4] = 0.002; // Variance on the acceleration for the 2nd signal (y)
  sigma_state[5] = 0.002; // Variance on the acceleration for the 2nd signal (y)
  // - Secondly, the measures variance
  vpColVector sigma_measure(nsignal); // 2 velocity measures available
  sigma_measure[0] = 0.03; // Variance on the x velocity measure
  sigma_measure[1] = 0.06; // Variance on the y velocity measure
  // - Thirdly, the correlation between succesive accelerations
  double rho = 0.9;
  // - Lastly, the sampling time
  double dt = 0.020; // 20 ms

  // Initialize the filter
  kalman.initStateConstAccWithColoredNoise_MeasureVel(nsignal, sigma_state, sigma_measure, rho, dt);

  // Does the filtering
  vpColVector vm(2); // Measured velocities
  for (; ; ) {
    // Get the two dimentional velocity measures
    // vm[0] = ...;
    // vm[1] = ...;

    // Compute the filtering and the prediction
    kalman.filter(vm);
    // Print the estimation of the velocities (1st value of the state vector)
    std::cout << "Estimated x velocity: kalman.Xest[0]" << std::endl;
    std::cout << "Estimated y velocity: kalman.Xest[kalman.getStateSize()]"
      << std::endl;
// The one step prediction is available in kalman.Xpre variable
  }
}
