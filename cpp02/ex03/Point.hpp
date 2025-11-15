#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float p1, const float p2);
		Point(const Point &p);
		~Point();
		float getX(void) const;
		float getY(void) const;
		Point& operator=(const Point& p_obj);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
