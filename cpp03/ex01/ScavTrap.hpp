#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &obj);
	void guardGate();
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& obj);
