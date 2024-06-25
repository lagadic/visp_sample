#include <visp3/core/vpForceTwistMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
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
#endif
}
