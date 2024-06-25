#include <visp3/visual_features/vpFeaturePoint.h>
#include <visp3/visual_features/vpFeatureBuilder.h>
#include <visp3/vs/vpServo.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  vpServo servo;
  servo.setServo(vpServo::EYEINHAND_CAMERA);
  servo.setLambda(0.8);
  servo.setInteractionMatrixType(vpServo::CURRENT);

  vpCameraParameters cam;
  vpDot2 dot[4];
  vpFeaturePoint s_x[4], s_x_star[4];
  vpImagePoint cog[4];
  vpHomogeneousMatrix cdMo(0, 0, 0.5, 0, 0, 0), cMo;
  vpImage<unsigned char> I;
  double L = 0.05;
  vpPoint p3D[4];
  p3D[0].setWorldCoordinates(-L, -L, 0);
  p3D[1].setWorldCoordinates(L, -L, 0);
  p3D[2].setWorldCoordinates(L, L, 0);
  p3D[3].setWorldCoordinates(-L, L, 0);

  for (int i = 0; i < 4; i++) {
    p3D[i].project(cdMo);
    s_x_star[i].set_x(p3D[i].get_x());
    s_x_star[i].set_y(p3D[i].get_y());
    s_x_star[i].set_Z(p3D[i].get_Z());
  }

  for (int i = 0; i < 4; i++)
    servo.addFeature(s_x[i], s_x_star[i]);

  vpColVector sum_dedt(servo.getDimension());

  while (1) {
    //I = acquire();
    //cog = track(I);
    //cMo = compute_pose(p3D, cog, cam);

    for (int i = 0; i < 4; i++) {
      vpFeatureBuilder::create(s_x[i], cam, dot[i]);
      p3D[i].changeFrame(cMo);

      s_x[i].set_Z(p3D[i].get_Z());
    }
    vpColVector v = servo.computeControlLaw();

    sum_dedt += servo.error;
    v -= 0.4*servo.getTaskJacobianPseudoInverse()*sum_dedt;

    //robot.setVelocity(vpRobot::CAMERA_FRAME, v);
  }
}
