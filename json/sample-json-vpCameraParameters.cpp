#include <visp3/core/vpCameraParameters.h>

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "cam.json";
  {
    vpCameraParameters cam(801, 802, 325, 245);
    std::ofstream file(filename);
    const nlohmann::json j = cam;
    file << j;
    file.close();
  }
  {
    std::ifstream file(filename);
    const nlohmann::json j = nlohmann::json::parse(file);
    vpCameraParameters cam;
    cam = j;
    file.close();
    std::cout << "Read camera parameters from " << filename << ":\n" << cam << std::endl;
  }
#endif
}
