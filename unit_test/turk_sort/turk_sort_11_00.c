#include"turk_sort.h"

int	main(int len, char **str)
{
	size_t			col = 11;
	t_2intlist		intlist;
	int				intarr[] = {210,	804,	442,	570,	213,	657,	651,	622,	380,	438,	846};
	int				*temp_intarr;
	int				*sorted_intarr;
	t_turk_costs	turk_cost;
	int				stop;
	bool			is_int;

	stop = 0;
	if (len > 1)
	{
		is_int = true;
		stop = f_atoi(str[1], &is_int, "0123456789", 0);
		if (is_int == false)
			stop = 0;
	}
	temp_intarr = clone_intarr(intarr, col);
	sorted_intarr = merge_sort(temp_intarr, col);
	intlist = load_2intlist(intarr, col);
	turk_cost = debug_turk_sort(&intlist, -2, (size_t)stop);
	if (is_intarr_and_list_same(sorted_intarr, intlist.a.item_1st, col, true) == true)
		write(1, "Correct\n", 9);
	else
	{
		write(1, "partial_progress: ", 19);
		ft_putnbr_fd(intlist.a.length, 1, "0123456789", 1);
		write(1, "\n", 1);
		write_intlist(intlist.a.item_1st, true, "stack_a: ");
		write_intlist(intlist.b.item_1st, true, "stack_b: ");
		write_intarr(turk_cost.target_a, turk_cost.length, "target_a: ");
		write_intarr(turk_cost.rotate_cost, turk_cost.length, "rotate_cost: ");
	}
	free_2intlist(&intlist);
	free(temp_intarr);
	free(sorted_intarr);
	free_turk_cost(&turk_cost);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_11_00.out


phsottat@z2t3c1 ~/Desktop/s_and_p/GreenSwap
 % valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_11_00.out 3
==826441== Memcheck, a memory error detector
==826441== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==826441== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==826441== Command: ./unit_test/out/turk_sort/turk_sort_11_00.out 3
==826441== 
partial_progress: 8
stack_a: 210, 213, 380, 438, 622, 651, 657, 846, 
stack_b: 570, 442, 804, 
target_a: 622, 622, 846, 
rotate_cost: 4, 4, -1, 
==826441== 
==826441== HEAP SUMMARY:
==826441==     in use at exit: 0 bytes in 0 blocks
==826441==   total heap usage: 25 allocs, 25 frees, 656 bytes allocated
==826441== 
==826441== All heap blocks were freed -- no leaks are possible
==826441== 
==826441== For lists of detected and suppressed errors, rerun with: -s
==826441== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
phsottat@z2t3c1 ~/Desktop/s_and_p/GreenSwap
 % valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/turk_sort/turk_sort_11_00.out 2
==826664== Memcheck, a memory error detector
==826664== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==826664== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==826664== Command: ./unit_test/out/turk_sort/turk_sort_11_00.out 2
==826664== 
partial_progress: 9
stack_a: 622, 651, 657, 846, 210, 213, 380, 438, 804, 
stack_b: 570, 442, 
target_a: 622, 622, 
rotate_cost: -4, -4, 
==826664== 
==826664== HEAP SUMMARY:
==826664==     in use at exit: 0 bytes in 0 blocks
==826664==   total heap usage: 27 allocs, 27 frees, 680 bytes allocated
==826664== 
==826664== All heap blocks were freed -- no leaks are possible
==826664== 
==826664== For lists of detected and suppressed errors, rerun with: -s
==826664== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/
