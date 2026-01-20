#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
class ClapTrap
{
	private:
	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;

	public:
	ClapTrap();
	ClapTrap(const ClapTrap &obj);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &obj);
	ClapTrap(std::string name);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamagePoints(void) const;
	
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& obj);


#endif