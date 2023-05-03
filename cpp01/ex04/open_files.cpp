#include "include.hpp"
#include <fstream>

bool open_files(std::string fileIn, std::string fileOut, std::ifstream* fi, std::ofstream* fo)
{
	fileOut = fileIn + ".replace";

	fi->open(fileIn.c_str(), std::fstream::in);

	if (!fi->is_open()) 
	{
		std::cerr << "Error cannot open infile." << std::endl;
    	fi->close();
		return (false);
	}

	if (fi->peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Error empty infile." << std::endl;
		fi->close();
		return (false);
	}

	fo->open(fileOut.c_str(), std::fstream::out);
	if (!fo->is_open())
	{
		std::cerr << "Error cannot open outfile." << std::endl;
		fi->close();
		fo->close();
		return (false);
	}
	return (true);
}
