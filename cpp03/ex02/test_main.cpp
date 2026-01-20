#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "========== FRAGTRAP TESTS ==========" << std::endl;
    
    std::cout << "\n=== CONSTRUCTION CHAIN TEST ===" << std::endl;
    FragTrap a("Alpha");
    
    std::cout << "\n=== INITIAL VALUES TEST ===" << std::endl;
    std::cout << a;
    std::cout << "(Expected: HP=100, EP=100, AD=30)" << std::endl;

    std::cout << "\n=== FRAGTRAP ATTACK TEST ===" << std::endl;
    a.attack("Enemy");
    
    std::cout << "\n=== INHERITED FUNCTIONS TEST ===" << std::endl;
    a.takeDamage(40);
    a.beRepaired(15);
    std::cout << a;
    
    std::cout << "\n=== HIGHFIVESGUYS SPECIAL ABILITY ===" << std::endl;
    a.highFivesGuys();

    std::cout << "\n=== EXHAUST ENERGY TEST ===" << std::endl;
    FragTrap b("Beta");
    std::cout << b;
    for (int i = 0; i < 100; i++)
        b.attack("Target");
    std::cout << "Energy after 100 attacks: " << b.getEnergyPoints() << std::endl;
    b.attack("Target");  // Should fail - no energy
    b.beRepaired(10);    // Should fail - no energy

    std::cout << "\n=== FATAL DAMAGE TEST ===" << std::endl;
    FragTrap c("Charlie");
    c.takeDamage(200);
    std::cout << c;
    c.attack("Target");  // Should fail - dead
    c.beRepaired(50);    // Should fail - dead

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===" << std::endl;
    FragTrap d(a);
    std::cout << d;

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
    FragTrap e("Echo");
    e = a;
    std::cout << e;

    std::cout << "\n=== ALL THREE CLASSES COMPARISON ===" << std::endl;
    ClapTrap clap("ClapBot");
    ScavTrap scav("ScavBot");
    FragTrap frag("FragBot");
    std::cout << "ClapTrap: " << clap;
    std::cout << "ScavTrap: " << scav;
    std::cout << "FragTrap: " << frag;
    std::cout << "\nAttacks:" << std::endl;
    clap.attack("Target");
    scav.attack("Target");
    frag.attack("Target");
    std::cout << "\nSpecial abilities:" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();

    std::cout << "\n=== DESTRUCTION CHAIN TEST ===" << std::endl;
    return 0;
}
