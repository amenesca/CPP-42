#include "Fixed.hpp"

Fixed::Fixed(void) : fpoint(0) {
  std::cout << "Default constructor called" << std::endl;  
}

Fixed::Fixed(Fixed const& fixed) {
  	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int const fpoint_int) {
	std::cout << "Int constructor called" << std::endl;
	this->fpoint = fpoint_int << this->frac_bits;
}

Fixed::Fixed(float const fpoint_float) {
	std::cout << "Float constructor called" << std::endl;
	this->fpoint = roundf(fpoint_float * (1 << this->frac_bits));
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->fpoint) / (1 << this->frac_bits));
}

int Fixed::toInt(void) const {
	return (static_cast<int>(this->fpoint) >> this->frac_bits);
}

Fixed& Fixed::operator=(Fixed const& fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->fpoint = fixed.getRawBits();
 	
	return *this;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const {
//  std::cout << "getRawBits member function called" << std::endl;
  return(this->fpoint);
}

void Fixed::setRawBits(int const raw) {
  this->fpoint = raw;
}
