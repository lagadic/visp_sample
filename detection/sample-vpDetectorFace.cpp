#include <visp3/core/vpConfig.h>
#include <visp3/detection/vpDetectorFace.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_OPENCV) && defined(HAVE_OPENCV_OBJDETECT)
  vpImage<unsigned char> I;
  vpDetectorFace face_detector;
  face_detector.setCascadeClassifierFile("haarcascade_frontalface_alt.xml");

  while (1) {
    // Acquire a new image in I
    bool face_found = face_detector.detect(I);
    if (face_found) {
      vpRect face_bbox = face_detector.getBBox(0); // largest face has index 0
    }
}
#endif
}
