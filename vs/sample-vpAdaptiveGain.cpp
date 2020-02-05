#include <visp3/vs/vpAdaptiveGain.h>
#include <visp3/vs/vpServo.h>

int main()
{
  vpAdaptiveGain lambda(0.5);

  vpServo servo;
  servo.setLambda(lambda);

  while(1) {

    vpColVector v = servo.computeControlLaw();
  }
}
