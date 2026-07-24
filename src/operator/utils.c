#include"operator.h"

// time : O(1)
// space: O(1)
bool	is_1_or_more(const t_int_list *src)
{
	if (src == NULL || src->item_1st == NULL
		|| src->item_last == NULL
		|| src->length < 1)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_2_or_more(const t_int_list *src)
{
	if (src == NULL || src->item_1st == NULL
		|| src->item_1st->future == NULL || src->item_last == NULL
		|| src->length < 2)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_both_stack_n_more(const t_green_swap *src,
			size_t min_a, size_t min_b)
{
	if (src != NULL
		&& is_1_or_more(&(src->a)) == true && src->a.length >= min_a
		&& is_1_or_more(&(src->b)) == true && src->b.length >= min_b)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_operator_available(e_operator operator, const t_int_list *dst)
{
	if (dst == NULL)
		return (false);
	if (operator != E_PUSH && is_2_or_more(dst) == true)
		return (true);
	if (operator == E_PUSH && is_1_or_more(dst) == true)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	write_operator(e_target target, e_operator operator, int show)
{
	if (show > -1 && target == TARGET_A && operator == E_PUSH)
		write(show, "pa\n", 3);
	if (show > -1 && target == TARGET_B && operator == E_PUSH)
		write(show, "pb\n", 3);
	if (show > -1 && target == TARGET_A && operator == E_SWAP)
		write(show, "sa\n", 3);
	if (show > -1 && target == TARGET_B && operator == E_SWAP)
		write(show, "sb\n", 3);
	if (show > -1 && target == TARGET_AB && operator == E_SWAP)
		write(show, "ss\n", 3);
	if (show > -1 && target == TARGET_A && operator == E_ROTATE)
		write(show, "ra\n", 3);
	if (show > -1 && target == TARGET_B && operator == E_ROTATE)
		write(show, "rb\n", 3);
	if (show > -1 && target == TARGET_AB && operator == E_ROTATE)
		write(show, "rr\n", 3);
	if (show > -1 && target == TARGET_A && operator == E_RROTATE)
		write(show, "rra\n", 3);
	if (show > -1 && target == TARGET_B && operator == E_RROTATE)
		write(show, "rrb\n", 3);
	if (show > -1 && target == TARGET_AB && operator == E_RROTATE)
		write(show, "rrr\n", 3);
}

