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
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if(this != &obj)
		ClapTrap::operator=(obj);
	return(*this);
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(energy_points <= 0 || hit_points <= 0)
		std::cout << "ScavTrap " << this->name << " can't attack!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage <<  " points of damage!" << std::endl;
		this->energy_points--;
	}
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScavTrap& obj)
{
	out << "name: " << obj.getName() << " | hit points: " << obj.getHitPoints() << " | energy points: " << obj.getEnergyPoints() << " | attack damage: " << obj.getAttackDamagePoints() << std::endl;
	return(out);
}



