#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_number = 0;
}

Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_number = x << this->fractional_bits;
}
Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_number = roundf(x * (1 << this->fractional_bits));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->fixed_number / (1 << this->fractional_bits));
}

int Fixed::toInt( void ) const
{
	return(this->fixed_number >> this->fractional_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return(out);
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
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
	return (this->fixed_number);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_number = raw;
}
