#include <visp3/core/vpConfig.h>
#include <visp3/core/vpPoseVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "pose-vector.json";
  {
    vpPoseVector pose(0.1, 0.2, 0.3, M_PI, M_PI_2, M_PI_4);
    std::ofstream file(filename);
    const nlohmann::json j = pose;
    file << j;
    file.close();
  }
  {
    std::ifstream file(filename);
    const nlohmann::json j = nlohmann::json::parse(file);
    vpPoseVector pose;
    pose = j;
    file.close();
    std::cout << "Read pose vector from " << filename << ":\n" << pose.t() << std::endl;
  }
#endif
}
