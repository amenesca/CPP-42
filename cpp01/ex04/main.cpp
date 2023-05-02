#include "include.hpp"

int main(int argc, char *argv[])
{
	std::string fileIn, find, replace, fileOut;
//	std::stringstream buff;
	std::ifstream fi;
	std::ofstream fo;
  bool error;

	if (argc != 4)
	{
		std::cerr << "sedisforloser only accepts 3 args, nor less, nor more." << std::endl;
		return (1);
	}

  error = init_var(&fileIn, &find, &replace, argv);
  
  if (error == false)
    return (-1);
  
  fileOut = fileIn + ".replace";

	fi.open(fileIn.c_str(), std::fstream::in);

	if (!fi.is_open() ) 
	{
	    std::cout << "Error cannot open file" << std::endl;
        return (2);
	}

	fo.open(fileOut.c_str(), std::fstream::out);

/*	buff << fi.rdbuf();
	inString = buff.str();

	while (1)
	{
		i = 0;
		i = inString.find(s1, i);
		if (i == std::string::npos)
			break;
		fo << inString.substr(0, i);
		fo << s2;
		i += s1.size();
		inString = inString.substr(i);
	}
	fo << inString;
	fi.close();
	fo.close();*/
	return (0);
}
