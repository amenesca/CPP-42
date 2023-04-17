#include "include.hpp"

int main()
{
	std::string file = "LoremIpsum";
	std::ifstream fi(file);
	std::ofstream fo(file + ".replace");
	std::string buff;

	if (!fi.is_open() && !fo.is_open()) 
	{
	    std::cout << "Error cannot open file" << std::endl;
        return 1;
	}

	while (getline(fi, buff))

	for (size_t i = 0; i < buff.size(); i++)
	{
		fo << buff[i];
	}
	std::cout << buff << std::endl;
	fi.close();
	fo.close();
	return (0);
}