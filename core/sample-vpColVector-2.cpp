#include <visp3/core/vpColVector.h>

int main()
{
  {
    vpMatrix X(3,3);
    X.resize(0,0);
  }

  {
    unsigned int w,h;
    vpMatrix X(h,w);
    X.resize(0,0);
  }

  {
    vpColVector A, B(5);
    for (unsigned int i=0; i<B.size(); i++)
      B[i] = i;
    A << B;
    std::cout << "A: \n" << A << std::endl;
  }

  {
    size_t n = 5;
    vpColVector A(n);
    double *B = new double [n];
    for (unsigned int i = 0; i < n; i++)
      B[i] = i;
    A << B;
    std::cout << "A: \n" << A << std::endl;
    delete [] B;
  }
}
