#include <iostream>
#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	int	n;

	if (ac == 1)
		return (0);
	n = 1;
	while (n < ac)
	{
		ScalarConverter::convert(*(av + n));
		n++;
	}
}