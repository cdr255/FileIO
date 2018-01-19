#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>


class FileIO {
public:
  std::fstream ip;
  std::vector<std::string> values;
  std::string delimiter;
  bool parsefile (std::fstream&, std::string);
  FileIO(std::string,std::string);
  ~FileIO();
};
