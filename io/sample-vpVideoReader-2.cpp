#include <visp3/io/vpVideoReader.h>
  
int main()
{
  vpImage<vpRGBa> I;

  vpVideoReader reader;
  
  // Initialize the reader.
  reader.setFileName("./image/image%04d.jpeg");
  reader.open(I);
  
  // Read the 3th frame
  reader.getFrame(I,2);

  return 0;
}
