#include <iostream>
#include <string>
#include <visp3/core/vpIoTools.h>

int main()
{
  // reading configuration file
  vpIoTools::loadConfigFile("/home/user/demo/config.txt");
  std::string nExp;vpIoTools::readConfigVar("expNumber", nExp); // nExp <- "2"
  double lambda;vpIoTools::readConfigVar("lambda", lambda);     // lambda <- 0.4
  bool use2D;vpIoTools::readConfigVar("use2D", use2D);          // use2D <- false
  bool use3D;vpIoTools::readConfigVar("use3D", use3D);          // use3D <- true
  bool doSave;vpIoTools::readConfigVar("save", doSave);         //  doSave <- false

  // creating name for experiment files
  vpIoTools::setBaseDir("/home/user/data");
  vpIoTools::setBaseName("exp" + nExp);         // full name <- "/home/user/data/exp2"
  vpIoTools::addNameElement("2D", use2D);       // full name <- "/home/user/data/exp2" since use2D==false
  vpIoTools::addNameElement("3D", use3D);       // full name <- "/home/user/data/exp2_3D"
  vpIoTools::addNameElement("lambda", lambda);  // full name <- "/home/user/data/exp2_3D_lambda0.4"

  // saving file
  vpIoTools::saveConfigFile(doSave); // would copy "/home/user/demo/config.txt" to "/home/user/data/exp2_3D_lambda0.4_config.txt" if doSave was true

  // create sub directory
  vpIoTools::createBaseNamePath();  // creates "/home/user/data/exp2_3D_lambda0.4/"
}
