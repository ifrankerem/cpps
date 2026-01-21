#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's constructor" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal's copy constructor" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal's destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal's copy assignment constructor" << std::endl;
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal" << std::endl;
}

std::string Animal::getType() const
{
	return(this->type);
}
