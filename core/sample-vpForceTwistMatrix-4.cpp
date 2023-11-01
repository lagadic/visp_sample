#include <visp3/core/vpForceTwistMatrix.h>

int main()
{
  {
    vpTranslationVector stp(0.1, 0.2, 0.3);
    vpRotationMatrix sRp({ 0,  0, -1,
                           0, -1,  0,
                          -1,  0,  0 });
    vpForceTwistMatrix sFp(stp, sRp);
    std::cout << "sFp:\n" << sFp << std::endl;
  }
  {
    vpRotationMatrix sRp({ 0,  0, -1,
                           0, -1,  0,
                          -1,  0,  0 });
    vpForceTwistMatrix sFp(sRp);
    std::cout << "sFp:\n" << sFp << std::endl;
  }
}
