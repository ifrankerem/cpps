#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog's constructor" << std::endl;
	this->type = "Dog";
	brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog's copy constructor" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog::~Dog()
{
	std::cout << "Dog's destructor" << std::endl;
	delete brain;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog's copy assignment constructor" << std::endl;
	if(this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "HAW HAW HAW HAW HAW" << std::endl;
}

void Dog::set_ideas(std::string idea)
{
	this->brain->set_ideas(idea);
}

std::string Dog::get_ideas() const
{
	return (this->brain->get_ideas());
}
