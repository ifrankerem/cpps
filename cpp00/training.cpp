#include <cstring>
#include <iostream>

namespace A
{
int		x = 31;
std::string hello(void)
{
	return ("naber lan");
}
} // namespace A

namespace B
{
int		x = 31;
std ::string hello(void)
{
	return ("NABER LAN");
}
} // namespace B

namespace MySpace
{
int		number = 42;
void	hello(void)
{
	std::cout << "Hello" << std::endl;
}
} // namespace MySpace

int	main(void)
{
	// std::cout << MySpace::number << std::endl;
	// MySpace::hello();
	std::cout << "B's x value " << B::x << std::endl;
	std::cout << "A's x value " << A::x << std::endl;
	std::cout << "ıts come frome B namespace " << B::hello() << std::endl;
	std::cout << "ıts come frome A namespace " << A::hello() << std::endl;
}