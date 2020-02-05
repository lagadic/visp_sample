#include <visp3/visual_features/vpFeaturePoint.h>
#include <visp3/vs/vpServo.h>

int main()
{
  vpServo servo;
  servo.setServo(vpServo::EYEINHAND_CAMERA);
  vpFeaturePoint s, sd;
  servo.addFeature(s, sd);

  vpColVector dof(6, 1);
  dof[0] = 0; // turn off vx
  dof[1] = 0; // turn off vy
  dof[2] = 0; // turn off vz
  dof[5] = 0; // turn off wz
  servo.setCameraDoF(dof);

  while(1) {
    // vpFeatureBuilder::create(s, ...);       // update current feature
    
    vpColVector v = servo.computeControlLaw(); // compute control law
    // only v[3] and v[4] corresponding to wx and wy are different from 0 
  }

  servo.kill();
}
