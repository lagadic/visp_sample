#include <visp3/core/vpConfig.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpServo servo;
  servo.setLambda(0.5);

  while (1) {

    vpColVector v = servo.computeControlLaw();
  }
}
