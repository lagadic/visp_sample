#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/robot/vpImageSimulator.h>

int main()
{
  vpImage<vpRGBa> Icamera(480,640,0);
  vpImage<vpRGBa> Iimage(60,60);

  // Initialise the image which will be projected into the image Icamera
  vpRGBa colorb(0,0,255);
  vpRGBa colorw(255,255,255);
  vpRGBa colorr(255,0,0);
  for(int i = 0; i < 60; i++)
    {
      for(int j = 0; j < 20; j++)
        Iimage[i][j] = colorb;
      for(int j = 20; j < 40; j++)
        Iimage[i][j] = colorw;
      for(int j = 40; j < 60; j++)
        Iimage[i][j] = colorr;
    }

  // Initialise the 3D coordinates of the Iimage corners
  vpColVector X[4];
  for (int i = 0; i < 4; i++) X[i].resize(3);
  // Top left corner
  X[0][0] = -1;
  X[0][1] = -1;
  X[0][2] = 0;

  // Top right corner
  X[1][0] = 1;
  X[1][1] = -1;
  X[1][2] = 0;

  // Bottom right corner
  X[2][0] = 1;
  X[2][1] = 1;
  X[2][2] = 0;

  //Bottom left corner
  X[3][0] = -1;
  X[3][1] = 1;
  X[3][2] = 0;

  vpImageSimulator sim;
  sim.init(Iimage, X);

  sim.setCameraPosition(vpHomogeneousMatrix(0,0,5,vpMath::rad(60),vpMath::rad(0),0));

  vpCameraParameters cam(868.0, 869.0, 320, 240);

  sim.getImage(Icamera,cam);

  vpImageIo::write(Icamera, "/tmp/I.pgm");

  return 0;
}
