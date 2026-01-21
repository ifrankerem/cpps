#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog's constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog's copy constructor" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog's copy assignment constructor" << std::endl;
	if(this != &other)
		Animal::operator=(other);
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "HAW HAW HAW HAW HAW" << std::endl;
}