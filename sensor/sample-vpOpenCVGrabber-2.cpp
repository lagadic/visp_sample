#include <iostream>

#include <visp3/core/vpConfig.h>

#if defined(VISP_HAVE_OPENCV) && (VISP_HAVE_OPENCV_VERSION < 0x030000)

#include <visp3/core/vpImage.h>
#include <visp3/core/vpImageConvert.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/sensor/vpOpenCVGrabber.h>


// usage: binary <device name>
// device name: 0 is the default to dial with the first camera,
//              1 to dial with a second camera attached to the computer
int main(int argc, char** argv)
{
  int device = 0;
  if (argc > 1)
    device = atoi(argv[1]);

  std::cout << "Use device: " << device << std::endl;
  cv::VideoCapture cap(device); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
    return -1;
  cv::Mat frame;
  cap >> frame; // get a new frame from camera

  IplImage iplimage = frame;
  std::cout << "Image size: " << iplimage.width << " "
      << iplimage.height << std::endl;

  //vpImage<vpRGBa> I; // for color images
  vpImage<unsigned char> I; // for gray images
  vpImageConvert::convert(&iplimage, I);
  vpDisplayOpenCV d(I);

  for(;;) {
    cap >> frame; // get a new frame from camera
    iplimage = frame;

    // Convert the image in ViSP format and display it
    vpImageConvert::convert(&iplimage, I);
    vpDisplay::display(I);
    vpDisplay::flush(I);
    if (vpDisplay::getClick(I, false)) // a click to exit
      break;
  }
  // the camera will be deinitialized automatically in VideoCapture destructor
  return 0;
}

#else
int main()
{
  std::cout << "OpenCV is not available..." << std::endl;
}

#endif
