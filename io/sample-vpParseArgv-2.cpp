#include <stdio.h>
#include <stdlib.h>
#include <visp3/io/vpParseArgv.h>
#include <visp3/core/vpMath.h>

// List of allowed command line options
#define GETOPTARGS	"bi:l:f:d:h" // double point mean here that the preceding option request an argument

// Usage : [-b] [-i <integer value>] [-l <long value>]
//         [-f <float value>] [-d <double value>] [-s <string value>] [-h]
int main(int argc, const char ** argv)
{
  // Variables to set by command line parsing
  bool   b_val = false;
  int    i_val = 10;
  long   l_val = 123456;
  float  f_val = 0.1f;
  double d_val = M_PI;
  std::string s_val;

  // Parse the command line to set the variables
  const char *optarg;
  int	c;
  while ((c = vpParseArgv::parse(argc, argv, GETOPTARGS, &optarg)) > 1) {

    switch (c) {
    case 'b': b_val = true; break;
    case 'i': i_val = atoi(optarg); break;
    case 'l': l_val = atol(optarg); break;
    case 'f': f_val = static_cast<float>(atof(optarg)); break;
    case 'd': d_val = atof(optarg); break;
    case 's': s_val = std::string(optarg); break;
    case 'h': printf("Usage: ...\n"); return EXIT_SUCCESS; break;

    default:
      printf("Usage: ...\n"); return EXIT_SUCCESS; break;
    }
  }
  if ((c == 1) || (c == -1)) {
    // standalone param or error
    printf("Usage: ...\n");
    return EXIT_FAILURE;
  }

  // b_val, i_val, l_val, f_val, d_val, s_val may have new values
}
