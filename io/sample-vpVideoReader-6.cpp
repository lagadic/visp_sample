#include <visp3/io/vpVideoReader.h>

int main()
{
  vpImage<vpRGBa> I;
  vpVideoReader reader;

  // Initialize the reader.
  reader.setFileName("./image/image%04d.jpeg");
  reader.setFirstFrameIndex(10);
  reader.setLastFrameIndex(20);
  reader.open(I);

  while (! reader.end() )
    reader >> I;
}
