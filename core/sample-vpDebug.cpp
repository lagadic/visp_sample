#ifndef VP_DEBUG
#  define VP_DEBUG      // Activate the debug mode
#endif
#define VP_DEBUG_MODE 2 // Activate debug level 1 and 2

#include <visp3/core/vpDebug.h>

int main()
{
  vpIN_FCT("main()");

  // Check the active debug levels
  std::cout << "Debug level 1 active: " << vpDEBUG_ENABLE(1) << std::endl;
  std::cout << "Debug level 2 active: " << vpDEBUG_ENABLE(2) << std::endl;
  std::cout << "Debug level 3 active: " << vpDEBUG_ENABLE(3) << std::endl;

  // C-like debug printings
  vpTRACE("C-like trace"); // stdout

  // Printing depend only VP_DEBUG_MODE value is >= 1
  vpTRACE(1, "C-like trace level 1");              // stdout
  vpERROR_TRACE(1, "C-like error trace level 1");  // stderr

  // Printing if VP_DEBUG defined and VP_DEBUG_MODE value >= 2
  vpDEBUG_TRACE(2, "C-like debug trace level 2");  // stdout
  vpDERROR_TRACE(2, "C-like error trace level 2"); // stderr

  // C++-like debug printings
  vpCTRACE << "C++-like debug trace" << std::endl; // stdout
  vpCERROR << "C++-like error trace" << std::endl; // stderr

  // Printing if VP_DEBUG defined and VP_DEBUG_MODE value >= 2
  vpCDEBUG(2) << "C++-like debug trace level 2" << std::endl; // stdout

  vpOUT_FCT("main()");
}
