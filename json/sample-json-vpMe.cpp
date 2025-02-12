#include <visp3/core/vpConfig.h>
#include <visp3/me/vpMe.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "me.json";
  {
    vpMe me;
    me.setLikelihoodThresholdType(vpMe::NORMALIZED_THRESHOLD);
    me.setThreshold(20);
    me.setMaskNumber(180);
    me.setMaskSign(0);
    me.setMu1(0.5);
    me.setMu2(0.5);
    me.setNbTotalSample(0);
    me.setPointsToTrack(200);
    me.setRange(5);
    me.setStrip(2);

    std::ofstream file(filename);
    const nlohmann::json j = me;
    file << j;
    file.close();
  }
  {
    std::ifstream file(filename);
    const nlohmann::json j = nlohmann::json::parse(file);
    vpMe me;
    me = j;
    file.close();
    std::cout << "Read moving-edges settings from " << filename << ":" << std::endl;
    me.print();
  }
#endif
}
