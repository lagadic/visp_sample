#include <visp3/core/vpConfig.h>
#include <visp3/vs/vpAdaptiveGain.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpAdaptiveGain lambda(0.5);

  vpServo servo;
  servo.setLambda(lambda);

  while (1) {

    vpColVector v = servo.computeControlLaw();
  }
}
