#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_number = 0;
}

Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	//fixed_number = obj.getRawBits();
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &obj)
		this->fixed_number = obj.getRawBits();
	return(*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_number << 8); // or *256
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_number = (8 >> raw); // or divide 256
}