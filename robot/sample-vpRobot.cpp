#include <iostream>

#include <visp3/robot/vpRobot.h>

int main()
{
  vpColVector v(6);
  v[0] = 0.1;
  v[1] = 0.2;
  v[2] = 0.3;
  v[3] = vpMath::rad(10);
  v[4] = vpMath::rad(-10);
  v[5] = vpMath::rad(20);

  vpColVector v_max(6);
  for (int i=0; i<3; i++)
    v_max[i] = 0.3;
  for (int i=3; i<6; i++)
    v_max[i] = vpMath::rad(10);

  vpColVector v_sat = vpRobot::saturateVelocities(v, v_max, true);

  std::cout << "v    : " << v.t() << std::endl;
  std::cout << "v max: " << v_max.t() << std::endl;
  std::cout << "v sat: " << v_sat.t() << std::endl;

  return 0;
}
