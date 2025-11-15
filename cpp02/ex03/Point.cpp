#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float p1, const float p2) : x(p1), y(p2)
{
	//std::cout << bla bla
}

Point::Point(const Point &p) : x(p.x), y(p.y)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	return ;
}

float Point::getX(void) const
{
	return(this->x.toFloat());
}

float Point::getY(void) const
{
	return(this->y.toFloat());
}

Point& Point::operator=(const Point& p_obj)
{
	(void)p_obj;
	return(*this);
}
