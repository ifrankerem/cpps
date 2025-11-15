#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap a ("kerem");
	ClapTrap b ("huseyin");

	std::cout << a << "\n" << b << std::endl;
	a.attack("huseyin");
	b.takeDamage(a.getAttackDamagePoints());
	b.beRepaired(31);
	std::cout << a << "\n" << b << std::endl;
}