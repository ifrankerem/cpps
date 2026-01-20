#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== CONSTRUCTOR TESTS ===" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Beta");
    
    std::cout << "\n=== INITIAL STATE ===" << std::endl;
    std::cout << a << b;
    
    std::cout << "\n=== ATTACK TEST ===" << std::endl;
    a.attack(b.getName());
    b.takeDamage(a.getAttackDamagePoints());
    std::cout << b;
    
    std::cout << "\n=== REPAIR TEST ===" << std::endl;
    b.beRepaired(5);
    std::cout << b;
    
    std::cout << "\n=== EXHAUST ENERGY TEST ===" << std::endl;
    for (int i = 0; i < 10; i++)
        a.attack("Target");
    std::cout << "Energy after 10 attacks: " << a.getEnergyPoints() << std::endl;
    a.attack("Target");  // Should fail - no energy
    
    std::cout << "\n=== TAKE FATAL DAMAGE TEST ===" << std::endl;
    b.takeDamage(100);
    std::cout << b;
    b.beRepaired(10);  // Should fail - dead
    b.attack("Target");  // Should fail - dead
    
    std::cout << "\n=== COPY CONSTRUCTOR TEST ===" << std::endl;
    ClapTrap c(a);
    std::cout << c;
    
    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
    ClapTrap d("Delta");
    d = a;
    std::cout << d;
    
    std::cout << "\n=== DESTRUCTORS ===" << std::endl;
    return 0;
}
