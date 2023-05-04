#include "include.hpp"

void find_replace(std::string find, std::string replace, std::ifstream *fi, std::ofstream *fo)
{
	std::string inString;
	std::stringstream buff;
	size_t i;

 	buff << fi->rdbuf();
	inString = buff.str();

	while (1)
	{
		i = 0;
		i = inString.find(find, i);
		if (i == std::string::npos)
			break;
		*fo << inString.substr(0, i);
		*fo << replace;
		i += find.size();
		inString = inString.substr(i);
	}
	*fo << inString;
	fi->close();
	fo->close();
}
