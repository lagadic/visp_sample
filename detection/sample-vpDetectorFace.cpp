#include <visp3/detection/vpDetectorFace.h>

int main()
{
#if (VISP_HAVE_OPENCV_VERSION >= 0x020200)
  vpImage<unsigned char> I;
  vpDetectorFace face_detector;
  face_detector.setCascadeClassifierFile("haarcascade_frontalface_alt.xml");

  while(1) {
    // acquire a new image in I
    bool face_found = face_detector.detect(I);
    if (face_found) {
      vpRect face_bbox = face_detector.getBBox(0); // largest face has index 0
    }
  }
#endif
}

