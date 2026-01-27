#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat's constructor" << std::endl;
	this->type = "Cat";
	brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat's copy constructor" << std::endl;
	this->brain = new Brain(*other.brain);
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
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "miyawwwww" << std::endl;
}


void Cat::set_ideas(std::string idea)
{
	this->brain->set_ideas(idea);
}

std::string Cat::get_ideas() const
{
	return (this->brain->get_ideas());
}
