#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fpoint(0) {
  std::cout << "Default constructor called" << std::endl;  
}

Fixed::Fixed(int fpoint) : fpoint(fpoint) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& fixed) {
  std::cout << "Copy assignment constructor called" << std::endl;
  if (this != &fixed) {
    fpoint = fixed.fpoint;
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  return(this->fpoint);
}

void Fixed::setRawBits(int const raw) {
  this->fpoint = raw;
}
