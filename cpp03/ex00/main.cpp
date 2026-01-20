#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap a ("kerem");
	ClapTrap b ("huseyin");

	std::cout << a << "\n" << b << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamagePoints());
	b.beRepaired(31);
	std::cout << "\n";
	std::cout << a << "\n" << b << std::endl;
}