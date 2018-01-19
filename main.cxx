#include "fileio.hxx"

int main (int argc, char * argv[])
{
  
  FileIO Loader ("data.csv",",");
  Loader.parsefile(Loader.ip, Loader.delimiter);
  return 0;
}

