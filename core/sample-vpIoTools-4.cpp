#include <visp3/core/vpIoTools.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::cout << vpIoTools::getIndex("file-1.txt", "file-%d.txt") << std::endl;
  std::cout << vpIoTools::getIndex("/tmp/file0040.txt", "/tmp/file%04d.txt") << std::endl;
  std::cout << vpIoTools::getIndex("file.txt", "file%d.txt") << std::endl;
  std::cout << vpIoTools::getIndex("file03.txt", "file%02d.txt") << std::endl;
  std::cout << vpIoTools::getIndex("file-03.txt", "file%02d.txt") << std::endl;
}
