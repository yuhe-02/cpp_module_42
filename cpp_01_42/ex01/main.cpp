#include "includes/Zombie.hpp"

int main() {
	int N = 3;
	std::string	name = "AAAA";
	Zombie *z = zombieHorde(N, name);

	if (z != NULL) {
		for (int i = 0; i < N; ++i) {
			z[i].announce();
		}
		delete[] z;
	}
	return (0);
}