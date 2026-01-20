#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if(this != &obj)
		ClapTrap::operator=(obj);
	return(*this);
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "GIVE ME HIGH FIVE MAAAN!!!" << std::endl;
}

//non-member oldugundan inherit edilemez bu nedenle 0 dan kendim yazdım FragTrap için

std::ostream& operator<<(std::ostream& out, const FragTrap& obj)
{
	out << "name: " << obj.getName() << " | hit points: " << obj.getHitPoints() << " | energy points: " << obj.getEnergyPoints() << " | attack damage: " << obj.getAttackDamagePoints() << std::endl;
	return(out);
}
