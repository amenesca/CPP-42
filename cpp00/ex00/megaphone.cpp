#include <iostream>

int main(int argc, char **argv)
{
	std::string args;
	int len;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			args = argv[i];
			len = args.length();
			for (int j = 0; j < len; j++)
				std::cout << (char)toupper(args[j]);
		}
		std::cout << std::endl;
	}
}
