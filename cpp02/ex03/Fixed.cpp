#include "Fixed.hpp"

//constructors

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->fixed_number = 0;
}

Fixed::Fixed(const int x)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fixed_number = x << 8;
}
Fixed::Fixed(const float x)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fixed_number = roundf(x * 256);
}

Fixed::Fixed(Fixed const &obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	//fixed_number = obj.getRawBits();
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//setter - getter

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_number);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_number = raw;
}

//toFunctions

float Fixed::toFloat( void ) const
{
	return ((float)this->fixed_number / 256.0f);
}

int Fixed::toInt( void ) const
{
	return(this->fixed_number >> this->fractional_bits);
}

//OPERATORS

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return(out);
}

Fixed &Fixed::operator=(const Fixed& obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if(this != &obj)
		this->fixed_number = obj.getRawBits();
	return(*this);
}

bool Fixed::operator>(const Fixed& obj) const
{
	return(this->fixed_number > obj.fixed_number);
}
bool Fixed::operator<(const Fixed& obj) const
{
	return(this->fixed_number < obj.fixed_number);
}
bool Fixed::operator>=(const Fixed& obj) const
{
	return(this->fixed_number >= obj.fixed_number);
}
bool Fixed::operator<=(const Fixed& obj) const
{
	return(this->fixed_number <= obj.fixed_number);
}
bool Fixed::operator==(const Fixed& obj) const
{
	return(this->fixed_number == obj.fixed_number);
}
bool Fixed::operator!=(const Fixed& obj) const
{
	return(this->fixed_number != obj.fixed_number);
}

Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed temp;
	temp.setRawBits(this->fixed_number + obj.fixed_number);
	return (temp);
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed temp;
	temp.setRawBits(this->fixed_number - obj.fixed_number);
	return (temp);
}
Fixed Fixed::operator*(const Fixed& obj) const
{
	Fixed temp;
	temp.setRawBits((this->fixed_number * obj.fixed_number) / 256);
	return (temp);
}
Fixed Fixed::operator/(const Fixed& obj) const
{
	Fixed temp;
	temp.setRawBits(((this->fixed_number * 256) / obj.fixed_number));
	return (temp);
}

Fixed& Fixed::operator++()
{
	this->fixed_number++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixed_number++;
	return(temp);
}

Fixed& Fixed::operator--()
{
	this->fixed_number--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixed_number--;
	return(temp);
}

Fixed& Fixed::min(Fixed& obj_1, Fixed& obj_2)
{
	if(obj_1.fixed_number > obj_2.fixed_number)
		return(obj_2);
	else
		return(obj_1);	
}

const Fixed& Fixed::min(const Fixed& obj_1, const Fixed&  obj_2)
{
	if(obj_1.fixed_number > obj_2.fixed_number)
		return(obj_2);
	else
		return(obj_1);	
}

Fixed& Fixed::max(Fixed& obj_1, Fixed& obj_2)
{
	if(obj_1.fixed_number > obj_2.fixed_number)
		return(obj_1);
	else
		return(obj_2);	
}

const Fixed& Fixed::max(const Fixed& obj_1, const Fixed&  obj_2)
{
	if(obj_1.fixed_number > obj_2.fixed_number)
		return(obj_1);
	else
		return(obj_2);	
}



