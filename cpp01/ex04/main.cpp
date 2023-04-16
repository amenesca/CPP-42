#include "include.hpp"

int main()
{
	std::fstream fi, fo;
	std::string buff;

	fi.open("LoremIpsum", std::fstream::in);
	fo.open("LoremIpsum.replace", std::fstream::out);

	if (!fi.is_open() && !fo.is_open()) 
	{
	    std::cout << "Error cannot open file" << std::endl;
        return 1;
	}

	while (getline(fi, buff))

	std::cout << buff << std::endl;
	fi.close();
	fo.close();
	return (0);
}