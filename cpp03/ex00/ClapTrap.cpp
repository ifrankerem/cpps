#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 10;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		this->hit_points = obj.hit_points;
		this->energy_points = obj.hit_points;
		this->attack_damage = obj.hit_points;
	}
	return(*this);
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 10;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage <<  " points of damage!" << std::endl;
	this->energy_points--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take damage " << amount << " hit points!" <<  std::endl;
	this->hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" << this->name << "repaired himself" << amount << "hit points!" <<  std::endl;
	this->hit_points += amount;
	this->energy_points--;
}
std::string ClapTrap::getName(void) const
{
	return(this->name);
}
int ClapTrap::getHitPoints(void) const
{
	return(this->hit_points);
}
int ClapTrap::getEnergyPoints(void) const
{
	return(this->energy_points);
}
int ClapTrap::getAttackDamagePoints(void) const
{
	return(this->attack_damage);
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& obj)
{
	out << "name: " << obj.getName() << " | hit points: " << obj.getHitPoints() << " | energy points: " << obj.getEnergyPoints() << " | attack damage: " << obj.getAttackDamagePoints() << std::endl;
	return(out);
}
