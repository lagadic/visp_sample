#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpVideoReader.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImage<unsigned char> I;
  vpVideoReader reader;

  // Initialize the reader.
  reader.setFileName("./image/image%04d.jpeg");
  reader.setFirstFrameIndex(10);
  reader.setLastFrameIndex(20);
  reader.open(I);

  while (!reader.end())
    reader >> I;
}
