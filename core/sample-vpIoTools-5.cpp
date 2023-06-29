#include <visp3/core/vpIoTools.h>

int main()
{
  std::string tmp_path = vpIoTools::getTempPath();
  std::cout << "Temp path: " << tmp_path << std::endl;

  std::string tmp_dir1 = vpIoTools::makeTempDirectory(tmp_path);
  std::cout << "Created unique temp dir1: " << tmp_dir1 << std::endl;

  std::string tmp_dir2_template = tmp_path + vpIoTools::path("/") + "dir_XXXXXX";
  std::string tmp_dir2 = vpIoTools::makeTempDirectory(tmp_dir2_template);
  std::cout << "Created unique temp dir2: " << tmp_dir2 << std::endl;

  if (vpIoTools::remove(tmp_dir1)) {
    std::cout << "Temp dir1 was deleted" << std::endl;
  }
  if (vpIoTools::remove(tmp_dir2)) {
    std::cout << "Temp dir2 was deleted" << std::endl;
  }
}
