#include "fileio.hxx"

int main (int argc, char * argv[])
{
  
  FileIO Loader ("data.csv",",",4);
  //  Loader.parsefile();
  Loader.savefile();
  return 0;
}

