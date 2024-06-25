#include <iostream>
#include <string>
#include <fstream>
#include <visp3/core/vpIoTools.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
  std::string username;
  vpIoTools::getUserName(username);

  // Test if a username directory exist. If no try to create it
  if (vpIoTools::checkDirectory(username) == false) {
    try {
      // Create a directory with name "username"
      vpIoTools::makeDirectory(username);
    }
    catch (...) {
      std::cout << "Cannot create " << username << " directory" << std::endl;
      return EXIT_FAILURE;
    }
  }
 // Create a empty filename with name "username/file.txt"
  std::ofstream f;
  std::string filename = username + "/file.txt";
  // Under Windows converts the filename string into "username\\file.txt"
  filename = vpIoTools::path(filename);
  std::cout << "Create: " << filename << std::endl;
  f.open(filename.c_str());
  f.close();

  // Rename the file
  std::string newfilename = username + "/newfile.txt";
  std::cout << "Rename: " << filename << " in: " << newfilename << std::endl;
  if (vpIoTools::rename(filename, newfilename) == false)
    std::cout << "Unable to rename: " << filename << std::endl;

  // Remove the file
  std::cout << "Remove: " << newfilename << std::endl;
  if (vpIoTools::remove(newfilename) == false)
    std::cout << "Unable to remove: " << newfilename << std::endl;

  return EXIT_SUCCESS;
}
