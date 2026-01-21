#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal's constructor" << std::endl;
	this->type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Wrong Animal's copy constructor" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal's destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Wrong Animal's copy assignment constructor" << std::endl;
	if(this != &other)
		this->type = other.type;
	return(*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(this->type);
}
