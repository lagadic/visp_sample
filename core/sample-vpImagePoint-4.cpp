#include <iostream>
#include <visp3/core/vpConfig.h>
#include <visp3/core/vpImagePoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpImagePoint start_pixel(10, 12);
  vpImagePoint end_pixel(20, 16);
  //vpImagePoint start_pixel(10.5, 12.2);
  //vpImagePoint end_pixel(20, 12);
  //vpImagePoint end_pixel(20.5, 16.2);
  //vpImagePoint end_pixel(21, 16.4);

  for (auto curr_pixel = start_pixel; curr_pixel.inSegment(start_pixel, end_pixel);
       curr_pixel = curr_pixel.nextInSegment(start_pixel, end_pixel)) {
    std::cout << "pixel: " << curr_pixel << std::endl;
    if (curr_pixel == end_pixel) break;
  }

  return EXIT_SUCCESS;
}
