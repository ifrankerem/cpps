#include "Bureaucrat.hpp"
#include "Form.hpp"
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
		hate.ft_increment(42);
		std::cout << hate << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat thorne("g",42);
		thorne.ft_decrement(109);
		std::cout << thorne << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	//--------------------------------------

	try{
		Form form1("form1",151,3);
		std::cout << form1 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Form form2("form2",-1,3);
		std::cout << form2 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Form form1("form1",3,151);
		std::cout << form1 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Form form2("form2",3,0);
		std::cout << form2 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat thorne("thorne",42);
		Form form1("form1",3,3);
		thorne.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat thorne("thorne",1);
		Form form1("form1",3,3);
		thorne.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}