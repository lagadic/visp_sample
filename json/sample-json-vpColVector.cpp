#include <visp3/core/vpColVector.h>

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "col-vector.json";
  {
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
    vpColVector v({ 1, 2, 3, 4 });
#else
    vpColVector v(4);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
#endif
    std::ofstream file(filename);
    const nlohmann::json j = v;
    file << j;
    file.close();
  }
  {
    std::ifstream file(filename);
    const nlohmann::json j = nlohmann::json::parse(file);
    vpColVector v;
    v = j.get<vpColVector>();
    file.close();
    std::cout << "Read homogeneous matrix from " << filename << ":\n" << v.t() << std::endl;
  }
#endif
}
