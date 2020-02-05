#include <visp3/core/vpArray2D.h>

int main()
{
  {
  vpArray2D<float> a(2, 3);
  a[0][0] = -1; a[0][1] =  -2; a[0][2] = -3;
  a[1][0] =  4; a[1][1] = 5.5; a[1][2] =  6;

  std::cout << "a:" << std::endl;
  for (unsigned int i = 0; i < a.getRows(); i++) {
    for (unsigned int j = 0; j < a.getCols(); j++) {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }
  }

  {
#ifdef VISP_HAVE_CXX11
  vpArray2D<float> a{ {-1, -2, -3}, {4, 5.5, 6.0f} };
  std::cout << "a:\n" << a << std::endl;
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
  vpArray2D<float> a;
  a = { {-1, -2, -3}, {4, 5.5, 6.0f} };
#endif
  }

  {
#ifdef VISP_HAVE_CXX11
  vpArray2D<float> a{ -1, -2, -3, 4, 5.5, 6.0f };
  a.reshape(2, 3);
#endif
  }
}
