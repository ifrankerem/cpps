#include "Point.hpp"

Point::Point()
{
	std::cout << "Default constructor called" << std::endl;
	this->x = 0;
	this->y = 0;
}

Point::Point(const float p1, const float p2)
{
	//std::cout << bla bla 
	Fixed(p1);

}

Fixed