#include"operator.h"

// time : O(1)
// space: O(1)
bool	is_1_or_more(t_int_list *src)
{
	if (src == NULL || src->item_1st == NULL
		|| src->item_last == NULL
		|| src->length < 1)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_2_or_more(t_int_list *src)
{
	if (src == NULL || src->item_1st == NULL
		|| src->item_1st->future == NULL || src->item_last == NULL
		|| src->length < 2)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_operator_available(e_operator operator, t_int_list *dst)
{
	if (dst == NULL)
		return (false);
	if (operator != ACT_PUSH && is_2_or_more(dst) == true)
		return (true);
	if (operator == ACT_PUSH && is_1_or_more(dst) == true)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	write_operator(e_target target, e_operator operator, int show)
{
	if (show > -1 && target == TARGET_A && operator == ACT_PUSH)
		write(show, "pa\n", 3);
	if (show > -1 && target == TARGET_B && operator == ACT_PUSH)
		write(show, "pb\n", 3);
	if (show > -1 && target == TARGET_A && operator == ACT_SWAP)
		write(show, "sa\n", 3);
	if (show > -1 && target == TARGET_B && operator == ACT_SWAP)
		write(show, "sb\n", 3);
	if (show > -1 && target == TARGET_AB && operator == ACT_SWAP)
		write(show, "ss\n", 3);
	if (show > -1 && target == TARGET_A && operator == ACT_ROTATE)
		write(show, "ra\n", 3);
	if (show > -1 && target == TARGET_B && operator == ACT_ROTATE)
		write(show, "rb\n", 3);
	if (show > -1 && target == TARGET_AB && operator == ACT_ROTATE)
		write(show, "rr\n", 3);
	if (show > -1 && target == TARGET_A && operator == ACT_RROTATE)
		write(show, "rra\n", 3);
	if (show > -1 && target == TARGET_B && operator == ACT_RROTATE)
		write(show, "rrb\n", 3);
	if (show > -1 && target == TARGET_AB && operator == ACT_RROTATE)
		write(show, "rrr\n", 3);
}

