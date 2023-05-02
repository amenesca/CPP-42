#include "include.hpp"

int main(int argc, char *argv[])
{
	std::string fileIn, find, replace, fileOut;
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
  
  error = open_files(fileIn, fileOut, &fi, &fo);
  if (error == false)
    return (-1);

  find_replace(find, replace, &fi, &fo);
 }
