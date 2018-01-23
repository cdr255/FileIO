#include "fileio.hxx"

int main (int argc, char * argv[])
{
  
  FileIO Loader ("data.csv",",",4);
  //  Loader.parsefile();
  std::vector<std::string> test = Loader.getentry(2);
  Loader.savefile();
  return 0;
}

