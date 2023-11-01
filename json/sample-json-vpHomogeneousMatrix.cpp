#include <visp3/core/vpHomogeneousMatrix.h>

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "homo-mat.json";
  {
    vpHomogeneousMatrix M(vpTranslationVector(0.1, 0.2, 0.3), vpRotationMatrix({ 0, 0, 1, 0, -1, 0, -1, 0, 0 }));

    std::ofstream file(filename);
    const nlohmann::json j = M;
    file << j;
    file.close();
  }
  {
    std::ifstream file(filename);
    const nlohmann::json j = nlohmann::json::parse(file);
    vpHomogeneousMatrix M;
    M = j;
    file.close();
    std::cout << "Read homogeneous matrix from " << filename << ":\n" << M << std::endl;
  }
#endif
}
