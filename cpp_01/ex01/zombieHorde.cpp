#include "./includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);

    Zombie *zombies_array = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombies_array[i].setName(name);
    return (zombies_array);
}