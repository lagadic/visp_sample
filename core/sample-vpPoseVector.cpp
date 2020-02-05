#include <visp3/core/vpPoseVector.h>

int main()
{
  {
  vpPoseVector pose;

  pose[0] = 0.1;    // tx
  pose[1] = 0.2;    // ty
  pose[2] = 0.3;    // tz

  pose[3] = M_PI;   // tux
  pose[4] = M_PI_2; // tux
  pose[5] = M_PI_4; // tuz
  std::cout << "pose vector:\n" << pose << std::endl;
  }

  {
  vpTranslationVector t;
  vpThetaUVector tu;

  t << 0.1, 0.2, 0.3;
  tu << M_PI, M_PI_2, M_PI_4;
  vpPoseVector pose(t, tu);
  std::cout << "pose vector:\n" << pose << std::endl;
  }

  {
  vpTranslationVector t;
  vpThetaUVector tu;
#ifdef VISP_HAVE_CXX11
  t = { 0.1, 0.2, 0.3 };
  tu = { M_PI, M_PI_2, M_PI_4 };
#endif
  vpPoseVector pose(t, tu);
  std::cout << "pose vector:\n" << pose << std::endl;
  }


}
