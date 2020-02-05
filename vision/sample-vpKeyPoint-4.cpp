#include <visp3/core/vpImage.h>
#include <visp3/core/vpDisplay.h>
#include <visp3/vision/vpKeyPoint.h>

int main()
{
#if (VISP_HAVE_OPENCV_VERSION >= 0x020300)
  vpImage<unsigned char> Ireference;
  vpImage<unsigned char> Icurrent;

  vpKeyPoint::vpFilterMatchingType filterType = vpKeyPoint::ratioDistanceThreshold;
  vpKeyPoint keypoint("ORB", "ORB", "BruteForce-Hamming", filterType);

  //First grab the reference image Irefrence
  //Add your code to load the reference image in Ireference

  //Select a part of the image by clincking on two points which define a rectangle
  vpImagePoint corners[2];
  for (int i=0 ; i < 2 ; i++)
  {
    vpDisplay::getClick(Ireference, corners[i]);
  }

  //Build the reference ORB points.
  int nbrRef;
  unsigned int height, width;
  height = (unsigned int)(corners[1].get_i() - corners[0].get_i());
  width = (unsigned int)(corners[1].get_j() - corners[0].get_j());
  nbrRef = keypoint.buildReference(Ireference, corners[0], height, width);

  //Then grab another image which represents the current image Icurrent

  //Select a part of the image by clincking on two points which define a rectangle
  for (int i=0 ; i < 2 ; i++)
  {
    vpDisplay::getClick(Icurrent, corners[i]);
  }

  //Match points between the reference points and the ORB points computed in the current image.
  int nbrMatched;
  height = (unsigned int)(corners[1].get_i() - corners[0].get_i());
  width = (unsigned int)(corners[1].get_j() - corners[0].get_j());
  nbrMatched = keypoint.matchPoint(Icurrent, corners[0], height, width);

  //Display the matched points
  keypoint.display(Ireference, Icurrent);
#endif

  return(0);
}
