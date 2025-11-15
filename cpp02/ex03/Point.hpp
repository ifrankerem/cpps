#include "Fixed.hpp"

class Point
{
	private:
		Fixed x;
		Fixed y;

	public:
		Point();
		Point(const float p1, const float p2);
		Point(Point &p);
		Point& operator=(const Point& obj);
		~Point();
		Fixed getPoints(void);
};