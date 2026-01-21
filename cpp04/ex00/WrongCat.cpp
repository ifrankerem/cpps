#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Wrong Cat's constructor" << std::endl;
	this->type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& other)  : WrongAnimal(other)
{
	std::cout << "Wrong Cat's copy constructor" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat's destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Wrong Cat's copy assignment constructor" << std::endl;
	if(this != &other)
		WrongAnimal::operator=(other);
	return(*this);
}

void WrongCat::makeSound() const
{
	std::cout << "moew!" << std::endl;
}
