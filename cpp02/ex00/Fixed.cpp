#include "Fixed.hpp"

Fixed::Fixed() : fpoint(0) {
	std::cout << "Default constructor called" << std::endl;  
}

Fixed::Fixed(Fixed const& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(Fixed const& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fpoint = fixed.getRawBits();
 	
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fpoint);
}

void Fixed::setRawBits(int const raw) {
	this->fpoint = raw;
}
