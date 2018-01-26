#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>


class FileIO {
public:
  std::vector<std::string> getentry(int);
  bool storeentry(int, std::vector<std::string>&);
  bool savefile ();
  FileIO(std::string,std::string,int);
  ~FileIO();
private:
  std::fstream file;
  std::vector<std::string> values;
  std::string delimiter,filename;
  int rowsize;
  int entries;
  bool parsefile ();
};
