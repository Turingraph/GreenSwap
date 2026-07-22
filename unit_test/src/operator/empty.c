#include"operator.h"

int	main(void)
{
	size_t			i;
	t_green_swap	dst;

	i = 0;
	act_push(NULL, NULL);
	act_swap(NULL);
	act_rotate(NULL);
	act_rrotate(NULL);
	dst.a.item_1st = NULL;
	dst.a.item_last = NULL;
	dst.a.length = 0;
	dst.b.item_1st = NULL;
	dst.b.item_last = NULL;
	dst.b.length = 0;
	i += write_available_operator(&dst, TARGET_A, 1, E_SWAP);
	i += (size_t)operate_green_swap(&dst, TARGET_A, E_SWAP, act_swap);
	i += write_available_operator(&dst, TARGET_B, 1, E_SWAP);
	i += (size_t)operate_green_swap(&dst, TARGET_B, E_SWAP, act_swap);
	i += write_available_operator(&dst, TARGET_A, 1, E_ROTATE);
	i += (size_t)operate_green_swap(&dst, TARGET_A, E_ROTATE, act_rotate);
	i += write_available_operator(&dst, TARGET_B, 1, E_ROTATE);
	i += (size_t)operate_green_swap(&dst, TARGET_B, E_ROTATE, act_rotate);
	i += write_available_operator(&dst, TARGET_A, 1, E_RROTATE);
	i += (size_t)operate_green_swap(&dst, TARGET_A, E_RROTATE, act_rrotate);
	i += write_available_operator(&dst, TARGET_B, 1, E_RROTATE);
	i += (size_t)operate_green_swap(&dst, TARGET_B, E_RROTATE, act_rrotate);
	i += write_available_operator(&dst, TARGET_A, 1, E_PUSH);
	i += (size_t)operate_green_swap(&dst, TARGET_A, E_PUSH, NULL);
	i += write_available_operator(&dst, TARGET_B, 1, E_PUSH);
	i += (size_t)operate_green_swap(&dst, TARGET_B, E_PUSH, NULL);
	write_total_score(i, 8);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/operator/empty.out
*/
