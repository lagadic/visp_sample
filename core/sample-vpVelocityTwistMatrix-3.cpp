#include <visp3/core/vpConfig.h>
#include <visp3/core/vpVelocityTwistMatrix.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  {
    vpTranslationVector cte(0.1, 0.2, 0.3);
    vpRotationMatrix cRe({ 0,  0, -1,
                           0, -1,  0,
                          -1,  0,  0 });
    vpVelocityTwistMatrix cVe(cte, cRe);
    std::cout << "cVe:\n" << cVe << std::endl;
  }
  {
    vpRotationMatrix cRe({ 0,  0, -1,
                           0, -1,  0,
                          -1,  0,  0 });

    vpVelocityTwistMatrix cVe(cRe);
    std::cout << "cVe:\n" << cVe << std::endl;
  }
#endif
}
