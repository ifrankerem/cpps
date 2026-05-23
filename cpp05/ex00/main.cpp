#include "Bureaucrat.hpp"
#include <climits>

int main()
{
	try{
		Bureaucrat a("a",151);
		std::cout << a << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat b("b",-31);
		std::cout << b << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat c("c",INT_MAX);
		std::cout << c << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat d("d",INT_MIN);
		std::cout << d << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat e("e",1);
		std::cout << e << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat f("f",150);
		std::cout << f << std::endl;

	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat g("g",42);
		std::cout << g << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat hate("g",42);
		hate.ft_increment();
		std::cout << hate << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat thorne("g",42);
		thorne.ft_decrement();
		std::cout << thorne << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}