#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool init_var(std::string* fileIn, std::string* find, std::string* replace, char* argv[]);
bool open_files(std::string fileIn, std::string fileOut, std::ifstream* fi, std::ofstream* fo);
void find_replace(std::string find, std::string replace, std::ifstream* fi, std::ofstream* fo);

#endif
