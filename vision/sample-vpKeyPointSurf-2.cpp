#include <visp3/core/vpImage.h>
#include <visp3/core/vpDisplay.h>
#include <visp3/vision/vpKeyPointSurf.h>

int main()
{
#if defined (VISP_HAVE_OPENCV_NONFREE) && (VISP_HAVE_OPENCV_VERSION < 0x030000)
  vpImage<unsigned char> Ireference;
  vpImage<unsigned char> Icurrent;
  vpKeyPointSurf surf;

  //First grab the reference image Irefrence

  //Select a part of the image by clincking on two points which define a rectangle
  vpImagePoint corners[2];
  for (int i=0 ; i < 2 ; i++)
  {
    vpDisplay::getClick(Ireference, corners[i]);
  }

  //Build the reference SURF points.
  int nbrRef;
  unsigned int height, width;
  height = (unsigned int)(corners[1].get_i() - corners[0].get_i());
  width = (unsigned int)(corners[1].get_j() - corners[0].get_j());
  nbrRef = surf.buildReference(Ireference, corners[0], height, width);

  //Then grab another image which represents the current image Icurrent

  //Select a part of the image by clincking on two points which define a rectangle
  for (int i=0 ; i < 2 ; i++)
  {
    vpDisplay::getClick(Icurrent, corners[i]);
  }

  //Match points between the reference points and the SURF points computed in the current image.
  int nbrMatched;
  height = (unsigned int)(corners[1].get_i() - corners[0].get_i());
  width = (unsigned int)(corners[1].get_j() - corners[0].get_j());
  nbrMatched = surf.matchPoint(Icurrent, corners[0], height, width);

  //Display the matched points
  surf.display(Ireference, Icurrent);

  return(0);
#endif
}
