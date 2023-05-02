#include "./include.hpp"
#include <iostream>

bool init_var(std::string* fileIn, std::string* find, std::string* replace, char* argv[])
{
  *fileIn = argv[1];
  *find = argv[2];
  *replace = argv[3];

  if (fileIn->empty() || find->empty() || replace->empty()) {
    std::cerr << "The args passed shall not be empty." << std::endl;
    return (false);
  }
  return (true);
}
