#include"dejavu.h"

int	main(void)
{
	write_total_score(0, 0);
	return (0);
}

/*
	if (kagerou_day((const int []){0, 1, 2, 3, 2}, 5) == false)
		write(1, "Nujabes\n", 9);
	else
		write(1, "J.S. Bach\n", 11);

valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/dejavu/a.out
*/