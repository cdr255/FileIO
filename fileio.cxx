#include "fileio.hxx"

FileIO::FileIO(std::string file, std::string delim)
{
  ip.open(file);
  delimiter = delim;
}

FileIO::~FileIO()
{
  ip.close();
}

bool FileIO::parsefile (std::fstream & ip, std::string delimiter)
{
  std::string token = "ERROR";
  size_t pos = 0;
  size_t index = 0;
  for (std::string line; getline(ip, line);)
    {
      printf("Line: %s\n", line.c_str());
      
      while ((pos = line.find(delimiter)) != std::string::npos)
	{
	  token = line.substr(0, line.find(delimiter));
	  values.push_back(token);
	  line.erase(0, pos + delimiter.length());
	  index++;
	}
      values.push_back(line);      
    }

  return true;
}
