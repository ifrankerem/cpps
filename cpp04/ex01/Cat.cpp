#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat's constructor" << std::endl;
	this->type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat& other)  : Animal(other)
{
	std::cout << "Cat's copy constructor" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor" << std::endl;
	delete brain;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat's copy assignment constructor" << std::endl;
	if(this != &other)
		Animal::operator=(other);
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "miyawwwww" << std::endl;
}
