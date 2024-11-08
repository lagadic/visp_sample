#include <visp3/core/vpRGBa.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpVideoReader.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<vpRGBa> I;

  vpVideoReader reader;

  // Initialize the reader.
  reader.setFileName("./image/image%04d.jpeg");
  reader.open(I);

  // Read the 3th frame
  reader.getFrame(I, 2);

  return 0;
}
