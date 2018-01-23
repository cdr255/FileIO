#include "fileio.hxx"

FileIO::FileIO(std::string name, std::string delim, int rows)
{
  filename = name;
  delimiter = delim;
  rowsize = rows;
  parsefile();
  file.close();
}

FileIO::~FileIO()
{
  file.close();
}

bool FileIO::parsefile ()
{
  file.open(filename, std::fstream::in );
  if (!file.is_open())
    {
      printf("File %s not open for parsing!\n", filename);
      return false;
    }
  else
    {
      std::string token = "ERROR";
      size_t pos = 0;
      size_t index = 0;
      for (std::string line; getline(file, line);)
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
      file.clear();
      entries = values.size() / rowsize;
      return true;
    }
 
}

bool FileIO::savefile ()
{
  file.open(filename, std::fstream::out | std::fstream::trunc);
  std::string output = "";
  printf("Number of Values Loaded: %d\n", values.size());
  printf("Number of Rows to Write: %d\n", values.size() / rowsize);
  for(int rowcounter=0;rowcounter < entries;rowcounter++)
    {
      for(int counter=0;counter < rowsize;counter++)
	{

	  if (counter != rowsize - 1)
	    output.append(values[counter] + ",");
	  else
	    output.append(values[counter]);
	}
      output.append("\n");
      values.erase(values.begin(), values.begin() + rowsize);
    }

  file.seekg(0, std::fstream::beg);
  file.write(output.c_str(), output.length());
  file.close();
  return true;
}


std::vector<std::string> FileIO::getentry(int entrynumber)
{
  std::vector<std::string> entry;
  if (entrynumber > entries)
    {
      printf("Error: Tried to Access Nonexistant entry from File %s", filename.c_str());
      return entry;
    }
  else
    {
      int offset = (entrynumber - 1) * rowsize ;
      for (int counter = offset;counter < offset + rowsize;counter++)
	{
	  printf("Entry Item: %s\n", values[counter].c_str());
	  entry.push_back(values[counter]);
	}
      printf("Accessed entry %d of file %s\n", offset, filename.c_str());
      return entry;
    }
}
