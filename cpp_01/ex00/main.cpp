#include "includes/Zombie.hpp"

int main() {
	Zombie *z = newZombie("allocate");
	z->announce();
	randomChump("stack");

	delete(z);
	return (0);
}