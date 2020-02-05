#include <visp3/blob/vpDot2.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/sensor/vp1394TwoGrabber.h>

int main()
{
#if defined(VISP_HAVE_DC1394_2)
  vpImage<unsigned char> I; // Create a gray level image container
  vp1394TwoGrabber g(false); // Create a grabber based on libdc1394-2.x third party lib
  g.acquire(I); // Acquire an image

#if defined(VISP_HAVE_X11)
  vpDisplayX d(I, 0, 0, "Camera view");
#endif
  vpDisplay::display(I);
  vpDisplay::flush(I);

  vpDot2 blob;
  // Set dot characteristics for the auto detection
  blob.setWidth(24);
  blob.setHeight(23);
  blob.setArea(412);
  blob.setGrayLevelMin(160);
  blob.setGrayLevelMax(255);
  blob.setGrayLevelPrecision(0.8);
  blob.setSizePrecision(0.65);
  blob.setEllipsoidShapePrecision(0.65);

  std::list<vpDot2> auto_detected_blob_list;
  std::list<vpDot2>::iterator it;
  blob.searchDotsInArea(I, 0, 0, I.getWidth(), I.getHeight(), auto_detected_blob_list);

  while(1) {
    g.acquire(I); // Acquire an image
    vpDisplay::display(I);

    for(it=auto_detected_blob_list.begin(); it != auto_detected_blob_list.end(); ++it) {
      (*it).setGraphics(true);
      (*it).track(I);
    }

    vpDisplay::flush(I);
  }
#endif
}
