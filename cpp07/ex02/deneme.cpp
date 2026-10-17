#include <iostream>

int main()
{
	int * a = new int();
	std::cout << *a << std::endl;
	std::cout << a << std::endl;
	delete(a);
	
	int *b = new int;
	std::cout << *b << std::endl;
	std::cout << b << std::endl;
	delete(b);
}