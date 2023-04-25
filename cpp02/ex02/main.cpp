#include <iostream>
#include "Fixed.hpp"

int main(void) {
Fixed a(5.6f);
Fixed b(5.5f);

if (a > b)
    std::cout << "a é maior que b" << std::endl;
else
    std::cout << "a não é maior que b" << std::endl;

if (a < b)
    std::cout << "a é menor que b" << std::endl;
else
    std::cout << "a não é menor que b" << std::endl;

return (0);
}