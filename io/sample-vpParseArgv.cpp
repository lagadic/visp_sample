#include <stdio.h>
#include <visp3/io/vpParseArgv.h>
#include <visp3/core/vpMath.h>

// Usage : [-bool] [-int <integer value>] [-long <long value>]
//         [-float <float value>] [-double <double value>] [-string <string value>] [-h]
int main(int argc, const char ** argv)
{
  // Variables to set by command line parsing
  bool   b_val = false;
  int    i_val = 10;
  long   l_val = 123456;
  float  f_val = 0.1f;
  double d_val = M_PI;
  char   *s_val;

  // Parse the command line to set the variables
  vpParseArgv::vpArgvInfo argTable[] =
  {
    {"-bool", vpParseArgv::ARGV_CONSTANT_BOOL, 0, (char *) &b_val,
     "Flag enabled."},
    {"-int", vpParseArgv::ARGV_INT, (char*) NULL, (char *) &i_val,
     "An integer value."},
    {"-long", vpParseArgv::ARGV_LONG, (char*) NULL, (char *) &l_val,
     "An integer value."},
    {"-float", vpParseArgv::ARGV_FLOAT, (char*) NULL, (char *) &f_val,
     "A float value."},
    {"-double", vpParseArgv::ARGV_DOUBLE, (char*) NULL, (char *) &d_val,
     "A double value."},
    {"-string", vpParseArgv::ARGV_STRING, (char*) NULL, (char *) &s_val,
     "A string value."},
    {"-h", vpParseArgv::ARGV_HELP, (char*) NULL, (char *) NULL,
     "Print the help."},
    {(char*) NULL, vpParseArgv::ARGV_END, (char*) NULL, (char*) NULL, (char*) NULL}
  } ;

  // Read the command line options
  if(vpParseArgv::parse(&argc, argv, argTable,
                        vpParseArgv::ARGV_NO_LEFTOVERS |
                        vpParseArgv::ARGV_NO_ABBREV |
                        vpParseArgv::ARGV_NO_DEFAULTS)) {
    return (false);
  }

  // b_val, i_val, l_val, f_val, d_val, s_val may have new values
}
