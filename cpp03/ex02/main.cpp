#include "FragTrap.hpp"


int main(void)
{
	ClapTrap f("Faruk");
	ClapTrap g("Rambo");

	//FragTrap c;
	FragTrap a ("kerem");
	FragTrap b ("huseyin");
	FragTrap d ("mehmet");
	std::cout << d << std::endl;
	d = a;
	std::cout << d << std::endl;
	//std::cout << d << std::endl;
	//std::cout << c << std::endl;
	//f.guardGate();
	a.highFivesGuys();
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamagePoints());
	b.beRepaired(31);
	std::cout << a << "\n" << b << std::endl;
	FragTrap e (b);
	std::cout << e << std::endl;
	f.attack(g.getName());
	g.takeDamage(f.getAttackDamagePoints());

	std::cout << g << std::endl;
	// b.guardGate();
}