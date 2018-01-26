#include "fileio.hxx"

int main (int argc, char * argv[])
{
  FileIO Loader ("data.csv",",",4);
  //  Loader.parsefile();
  std::vector<std::string> test = Loader.getentry(2);
  test.at(3) = "Orange";
  for (int counter=0; counter < 4; counter++)
    printf("Test entry %d: %s\n", counter, test.at(counter).c_str());
  if (!Loader.storeentry(5, test))
    printf("Errors occurred. File not updated.\n");
  Loader.savefile();
  return 0;
}
