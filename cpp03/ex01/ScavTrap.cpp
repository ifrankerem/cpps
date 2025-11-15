#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	ClapTrap();
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	ClapTrap(name);
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	ClapTrap(obj);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
	
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if(this != &obj)
		*this = obj; // emin değilim
	return(*this);
}

void ScavTrap::guardGate()
{
	std::cout << " ScavTrap is now in Gate keeper mode" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScavTrap& obj)
{
	out << obj;
	return(out);
}
