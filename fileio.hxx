#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>


class FileIO {
public:
  std::fstream file;
  std::vector<std::string> values;
  std::string delimiter,filename;
  int rowsize;
  bool parsefile ();
  bool savefile ();
  FileIO(std::string,std::string,int);
  ~FileIO();
};
