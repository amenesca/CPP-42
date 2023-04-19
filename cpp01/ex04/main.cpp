#include "include.hpp"

/*int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong arguments" << std::endl;
		return (1);
	}
	std::string file = argv[1];
	std::string buff, s1 = argv[2], s2 = argv[3];
	std::ifstream fi(file);
	std::ofstream fo(file + ".replace");
	size_t aux, j;

	if (!fi.is_open() && !fo.is_open()) 
	{
	    std::cout << "Error cannot open file" << std::endl;
        return (2);
	}

	while (getline(fi, buff))
	{
		for (size_t i = 0; i < buff.size(); i++)
		{
			if (buff[i] == s1[0])
			{
				aux = i;
				j = 0;
				while (j < s1.size())
				{
					if (buff[aux] != s1[j])
						break ;
					aux++;
					j++;
				}
				if (j == s1.size())
				{
					fo << s2;
					i += s1.size();
				}
			}
			fo << buff[i];
		}
	}
	fi.close();
	fo.close();
	return (0);
}*/

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong arguments" << std::endl;
		return (1);
	}
	std::string file = argv[1];
	std::string inString, outString, s1 = argv[2], s2 = argv[3];
	std::stringstream buff;
	std::ifstream fi(file);
	std::ofstream fo(file + (std::string)".replace");
	size_t i = 0;

	if (!fi.is_open() && !fo.is_open()) 
	{
	    std::cout << "Error cannot open file" << std::endl;
        return (2);
	}

	buff << fi.rdbuf();
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
	fo.close();
	return (0);
}