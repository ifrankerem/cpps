#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float line_1 = ((b.getX() - a.getX()) * (point.getY() - a.getY())) - ((b.getY() - a.getY()) * (point.getX() - a.getX()));
	float line_2 = ((c.getX() - b.getX()) * (point.getY() - b.getY())) - ((c.getY() - b.getY()) * (point.getX() - b.getX()));
	float line_3 = ((a.getX() - c.getX()) * (point.getY() - c.getY())) - ((a.getY() - c.getY()) * (point.getX() - c.getX()));

	if((line_1 > 0 && line_2 > 0 && line_3 > 0 ) || (line_1 < 0 && line_2 < 0 && line_3 < 0 ))
		return(true);
	else
		return(false);
}