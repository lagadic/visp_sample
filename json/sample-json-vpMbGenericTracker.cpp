#include <visp3/mbt/vpMbGenericTracker.h>

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "mbt-generic.json";
  {
    vpMbGenericTracker mbt;
    mbt.saveConfigFile(filename);
  }
  {
    vpMbGenericTracker mbt;
    bool verbose = false;
    std::cout << "Read model-based tracker settings from " << filename << std::endl;
    mbt.loadConfigFile(filename, verbose);
  }
#endif
}
