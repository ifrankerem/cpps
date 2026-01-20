#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== CONSTRUCTION CHAIN TEST ===" << std::endl;
    ScavTrap a("Alpha");
    std::cout << "\n=== INITIAL VALUES TEST ===" << std::endl;
    std::cout << a;
    std::cout << "(Expected: HP=100, EP=50, AD=20)" << std::endl;

    std::cout << "\n=== SCAVTRAP ATTACK TEST (Different from ClapTrap) ===" << std::endl;
    a.attack("Enemy");
    
    std::cout << "\n=== INHERITED FUNCTIONS TEST ===" << std::endl;
    a.takeDamage(30);
    a.beRepaired(10);
    std::cout << a;
    
    std::cout << "\n=== GUARDGATE SPECIAL ABILITY ===" << std::endl;
    a.guardGate();

    std::cout << "\n=== EXHAUST ENERGY TEST ===" << std::endl;
    ScavTrap b("Beta");
    std::cout << b;
    for (int i = 0; i < 50; i++)
        b.attack("Target");
    std::cout << "Energy after 50 attacks: " << b.getEnergyPoints() << std::endl;
    b.attack("Target");  // Should fail - no energy
    b.beRepaired(10);    // Should fail - no energy

    std::cout << "\n=== FATAL DAMAGE TEST ===" << std::endl;
    ScavTrap c("Charlie");
    c.takeDamage(150);
    std::cout << c;
    c.attack("Target");  // Should fail - dead
    c.beRepaired(50);    // Should fail - dead

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===" << std::endl;
    ScavTrap d(a);
    std::cout << d;

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
    ScavTrap e("Echo");
    e = a;
    std::cout << e;

    std::cout << "\n=== CLAPTRAP VS SCAVTRAP COMPARISON ===" << std::endl;
    ClapTrap clap("ClapBot");
    ScavTrap scav("ScavBot");
    std::cout << "ClapTrap: " << clap;
    std::cout << "ScavTrap: " << scav;
    clap.attack("Target");
    scav.attack("Target");

    std::cout << "\n=== DESTRUCTION CHAIN TEST ===" << std::endl;
    return 0;
}
