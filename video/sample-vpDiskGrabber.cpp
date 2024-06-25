#include <visp3/core/vpImage.h>
#include <visp3/io/vpDiskGrabber.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  try {
    vpImage<unsigned char> I; // Grey level image

    // Declare a framegrabber able to read a sequence of successive
    // images from the disk
    vpDiskGrabber g;

    // Set the path to the directory containing the sequence
    g.setDirectory("/local/soft/ViSP/ViSP-images/cube");
    // Set the image base name. The directory and the base name constitute
    // the constant part of the full filename
    g.setBaseName("image.");
    // Set the step between two images of the sequence
    g.setStep(2);
    // Set the number of digits to build the image number
    g.setNumberOfZero(4);
    // Set the first frame number of the sequence
    g.setImageNumber(1);
    // Set the image file extension
    g.setExtension("pgm");

    // Open the framegrabber by loading the first image of the sequence
    g.open(I);

    unsigned int cpt = 1;
    // this is the loop over the image sequence
    while (cpt++ < 10) {
  // read the image and then increment the image counter so that the next
  // call to acquire(I) will get the next image
      g.acquire(I);
    }
  }
  catch (...) { }
}
