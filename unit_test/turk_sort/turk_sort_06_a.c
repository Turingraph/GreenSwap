#include"turk_sort.h"

int	main(void)
{
	size_t			col_a = 3;
	size_t			col = 3;
    t_turk_costs    turk_cost;
	int				rotate_arr[] = {-1, -1, -1};
	int				target_arr[] = {101, 101, 101};
	size_t			cheap_trick;

	cheap_trick = 0;
	turk_cost.length = col;
    turk_cost.capacity = col;
    turk_cost.rotate_cost = clone_intarr(rotate_arr, col);
	write_intarr(turk_cost.rotate_cost, turk_cost.length, ">>> 00: ");
    turk_cost.target_a = clone_intarr(target_arr, col);
	if (turk_cost.rotate_cost[cheap_trick] >= 0)
	{
		write(1, "Yoasobi\n", 9);
		rotate_value(turk_cost.rotate_cost, turk_cost.length,
			turk_cost.rotate_cost[cheap_trick], col_a);
	}
	else
	{
		write(1, "Yorushika\n", 11);
		rrotate_value(turk_cost.rotate_cost, turk_cost.length,
			turk_cost.length + turk_cost.rotate_cost[cheap_trick],
			col_a);
	}
	write_intarr(turk_cost.rotate_cost, turk_cost.length, ">>> 01: ");
	rotate_turk_cost(&turk_cost, cheap_trick);
	write_intarr(turk_cost.rotate_cost, turk_cost.length, ">>> 02: ");
	shift_arr(turk_cost.target_a, turk_cost.length);
	shift_arr(turk_cost.rotate_cost, turk_cost.length);
	turk_cost.length -= 1;
	write_intarr(turk_cost.rotate_cost, turk_cost.length, ">>> 03: ");
	// turk_cost.length -= 1;
	// if (101 < 54)
	// 	reverse_turk_cost(turk_cost, &(src->b), src->a.length);
	free_turk_cost(&turk_cost);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_06_a.out

*/
