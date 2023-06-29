#include <visp3/core/vpHomogeneousMatrix.h>

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "homo-mat.json";
  {
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
    vpHomogeneousMatrix M(vpTranslationVector(0.1, 0.2, 0.3), vpRotationMatrix({ 0, 0, 1, 0, -1, 0, -1, 0, 0 }));
#else
    vpHomogeneousMatrix M;
    M[0][0] = 0; M[0][1] = 0; M[0][2] = 1; M[0][2] = 0.1;
    M[1][0] = 0; M[1][1] = -1; M[1][2] = 0; M[1][2] = 0.2;
    M[2][0] = -1; M[2][1] = 0; M[2][2] = 0; M[2][2] = 0.3;
#endif
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
