#include <visp3/vs/vpAdaptiveGain.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpAdaptiveGain lambda(4, 0.4, 30);   // lambda(0)=4, lambda(oo)=0.4 and lambda'(0)=30

  vpServo servo;
  servo.setLambda(lambda);

  while (1) {

    vpColVector v = servo.computeControlLaw();
  }
}
