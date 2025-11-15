#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
	
ScavTrap &ScavTrap::operator=(const ScavTrap &obj) : operator=(obj)
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
