#include <visp3/core/vpConfig.h>
#include <visp3/io/vpImageIo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<vpRGBa> I;
  vpImageIo::read(I, "ballons.jpg");
}
