#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	ScavTrap scp;
	ScavTrap scp2(scp);
	for (int i = 0; i < 100 ; i++) {
		scp2.attack();
	}
	scp2.guardGate();
	return (0);
}