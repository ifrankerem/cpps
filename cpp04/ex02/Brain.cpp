#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain's constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain's copy constructor" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain's destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brains's copy assignment constructor" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return(*this);
}

void Brain::set_ideas(std::string idea)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

std::string Brain::get_ideas() const
{
	return(this->ideas[0]);
}
