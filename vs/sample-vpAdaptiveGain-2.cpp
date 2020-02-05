#include <visp3/vs/vpServo.h>

int main()
{
  vpServo servo;
  servo.setLambda(0.5);

  while(1) {

    vpColVector v = servo.computeControlLaw();
  }
}
