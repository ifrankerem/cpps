#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap a ("kerem");
	ScavTrap b ("huseyin");

	std::cout << a << "\n" << b << std::endl;
	a.attack("huseyin");
	b.takeDamage(a.getAttackDamagePoints());
	b.beRepaired(31);
	b.guardGate();
	std::cout << a << "\n" << b << std::endl;
}