#include "Point.hpp"

int main()
{
	// in
	Point p1(0,0);
	Point p2(5,0);
	Point p3(0,5);
	Point point_1(1,1);
	std::cout << bsp(p1,p2,p3,point_1) << std::endl;
	// on edge
	Point point_2(3,0);
	std::cout << bsp(p1,p2,p3,point_2) << std::endl;
	// out
	Point point_3(4,4);
	std::cout << bsp(p1,p2,p3,point_3) << std::endl;
	// in
	Point p4(2,1);
	Point p5(6,3);
	Point p6(4,7);
	Point point_4(4,4);
	std::cout << bsp(p4,p5,p6,point_4) << std::endl;
	// out
	Point p7(-2,1);
	Point p8(3,3);
	Point p9(1,8);
	Point point_5(5,5);
	std::cout << bsp(p7,p8,p9,point_5) << std::endl;
}
