#include <iostream>
#include "Fixed.hpp"

int main(void) {
Fixed a(5.6f);
Fixed b(5.5f);
Fixed c;

c = b - a;

std::cout << c << std::endl;
return (0);
}