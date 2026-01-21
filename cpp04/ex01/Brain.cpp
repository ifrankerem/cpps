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

// Brain& Brain::operator=(const Brain& other)
// {
// 	std::cout << "Brains's copy assignment constructor" << std::endl;
// 	if(this != &other)
// 		this->ideas = other.ideas;
// 	return(*this);
// }
