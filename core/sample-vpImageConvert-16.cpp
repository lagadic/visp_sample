#include <visp3/io/vpImageIo.h>

int main()
{
  vpImage<vpRGBa> I;
  vpImageIo::read(I, "ballons.jpg");
}
