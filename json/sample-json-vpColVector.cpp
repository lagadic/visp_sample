#include <visp3/core/vpConfig.h>
#include <visp3/core/vpColVector.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#if defined(VISP_HAVE_NLOHMANN_JSON)
  std::string filename = "col-vector.json";
  {
    vpColVector v({ 1, 2, 3, 4 });

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
