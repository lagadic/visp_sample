#include <visp3/core/vpImage.h>
#include <visp3/core/vpArray2D.h>
#include <visp3/klt/vpKltOpencv.h>
#include <visp3/core/vpImageConvert.h>

int main()
{
#if (VISP_HAVE_OPENCV_VERSION >= 0x010100) && (VISP_HAVE_OPENCV_VERSION < 0x020408)
  vpImage<unsigned char> I;
  IplImage* Icv = NULL;
  vpKltOpencv klt;

  //First grab the initial image I

  //Convert the image I to the IplImage format.
  vpImageConvert::convert(I, Icv);

  //Initialise the tracking on the whole image.
  klt.initTracking(Icv, NULL);

  while(true)
  {
    // Grab a new image and convert it to the OpenCV format.
    vpImageConvert::convert(I, Icv);

    // Track the features on the current image.
    klt.track(Icv);

    // Display the features tracked at the current iteration.
    klt.display(I);
  }

  cvReleaseImage(&Icv);
#else
  std::cout << "vpKltOpencv requires ViSP with OpenCV." << std::endl;
#endif
  return(0);
}

