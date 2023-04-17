#include "include.hpp"

int main(int argc, char *argv[])
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
	fi.close();
	fo.close();
	return (0);
}

/*#include "include.hpp"

int main(int argc, char *argv[])
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
	size_t find, i, j;

	if (!fi.is_open() && !fo.is_open()) 
	{
	    std::cout << "Error cannot open file" << std::endl;
        return (2);
	}

	while (getline(fi, buff))

	i = 0;
	j = 0;
	while (buff.find(s1, i) != std::string::npos && s1.size() != 0)
	{
		find = buff.find(s1, i);
		fo << buff.substr(j, find);
		j += find;
		fo << s2;
		j += s1.size();
		i = j;
	}
	fo << buff.substr(j);
	fi.close();
	fo.close();
	return (0);
}*/