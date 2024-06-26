#include <visp3/gui/vpDisplayX.h>
#include <visp3/core/vpImage.h>
#include <visp3/core/vpImagePoint.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_X11
  vpImage<unsigned char> I(600, 700);
  vpDisplayX display;
  display.init(I, 20, 20, "Track ball...");
  vpImagePoint dummy, pos_text, center, pointer, ip1, ip2;
  vpMouseButton::vpMouseButtonType button;
  int radius = 20;

  vpDisplay::display(I);
  std::string text;
  bool motion_allowed = false;
  center.set_u(I.getWidth()/2);
  center.set_v(I.getHeight()/2);

  for (; ; ) {
    vpDisplay::display(I);
    //vpDisplay::setBackground(I, vpColor::black);
    pos_text.set_u(30);
    pos_text.set_v(30);
    if (motion_allowed)
      text = "A left click to stop target motion...";
    else
      text = "A left click to start target motion...";
    vpDisplay::displayText(I, pos_text, text, vpColor::red);
    pos_text.set_u(30);
    pos_text.set_v(45);
    text = "A right click to quit...";
    vpDisplay::displayText(I, pos_text, text, vpColor::red);

    if (vpDisplay::getPointerMotionEvent(I, pointer)) {
      if (motion_allowed) {
        center = pointer;
        //std::cout << "focus: " << pointer << std::endl;
      }
    }
    ip1.set_u(center.get_u());
    ip1.set_v(center.get_v() - 6*radius);
    ip2.set_u(center.get_u());
    ip2.set_v(center.get_v() - 4*radius);
    vpDisplay::displayLine(I, ip1, ip2, vpColor::white, true);
    ip1.set_u(center.get_u() - 6*radius);
    ip1.set_v(center.get_v());
    ip2.set_u(center.get_u() - 4*radius);
    ip2.set_v(center.get_v());
    vpDisplay::displayLine(I, ip1, ip2, vpColor::white, true);
    ip1.set_u(center.get_u());
    ip1.set_v(center.get_v() + 6*radius);
    ip2.set_u(center.get_u());
    ip2.set_v(center.get_v() + 4*radius);
    vpDisplay::displayLine(I, ip1, ip2, vpColor::white, true);
    ip1.set_u(center.get_u() + 6*radius);
    ip1.set_v(center.get_v());
    ip2.set_u(center.get_u() + 4*radius);
    ip2.set_v(center.get_v());
    vpDisplay::displayLine(I, ip1, ip2, vpColor::white, true);
    vpDisplay::displayCircle(I, center, 2*radius, vpColor::white, true);
    //     vpDisplay::displayCircle(I, center, 1.5*radius, vpColor::black, true);
    //     vpDisplay::displayCircle(I, center, radius, vpColor::white, true);
    // vpDisplay::displayCircle(I, center, 5*radius, vpColor::white, false);

    if (vpDisplay::getClick(I, dummy, button, false)) {
      // A click event was detected
      if (button == vpMouseButton::button3)
        break;
      else if (button == vpMouseButton::button1) {
        if (motion_allowed)
          motion_allowed = false;
        else
          motion_allowed = true;
      }
    }
    vpDisplay::flush(I);
    vpTime::wait(1);
  }
#endif

  return 0;
}
