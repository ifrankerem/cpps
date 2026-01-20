#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		this->hit_points = obj.hit_points;
		this->energy_points = obj.energy_points;
		this->attack_damage = obj.attack_damage;
	}
	return(*this);
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if(energy_points <= 0 || hit_points <= 0)
		std::cout << "ClapTrap " << this->name << " can't attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage <<  " points of damage!" << std::endl;
		this->energy_points--;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take damage " << amount << " hit points!" <<  std::endl;
	this->hit_points -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy_points <= 0 || hit_points <= 0)
		std::cout << "ClapTrap " << this->name << " can't be repaired" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " repaired himself " << amount << " hit points!" <<  std::endl;
		this->hit_points += amount;
		this->energy_points--;
	}
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
