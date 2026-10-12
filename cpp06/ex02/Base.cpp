#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <typeinfo>

Base::Base()
{
}

Base::Base(const Base& other)
{
    *this = other;
}

Base& Base::operator=(const Base& other)
{
    if (this != &other)
    {
        
    }

    return *this;
}

Base::~Base()
{
}


Base* Base::generate()
{
	int random_nbr = std::rand() % 3;

	Base *x;
	if(random_nbr == 0)
		x = new A();
	else if(random_nbr == 1)
		x = new B();
	else
		x = new C();
	return x;
}

void Base::identify(Base *p)
{
	A* a = dynamic_cast<A*>(p);
	if(a)
		std::cout << "A" << std::endl;
	else
	{
		B* b = dynamic_cast<B*>(p);
		if(b)
			std::cout << "B" << std::endl;
		else
			std::cout << "C" << std::endl;
	}
}

void Base::identify(Base &p)
{
	try {

		A &a = dynamic_cast<A&>(p);
		(void)a;

		std::cout << "A" << std::endl;

	} 
	catch (std::bad_cast&) {

		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		
		} catch (std::bad_cast&) {
			std::cout << "C" << std::endl;

		}
	}
}