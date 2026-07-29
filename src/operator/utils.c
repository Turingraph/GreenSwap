#include"operator.h"

// time : O(1)
// space: O(1)
bool	is_intlist_n_more(const t_intlist *src, size_t length)
{
	if (src != NULL
		&& src->item_1st == NULL
		&& src->item_last == NULL
		&& src->length == 0 && length == 0)
		return (true);
	if (src != NULL
		&& src->item_1st != NULL
		&& src->item_last != NULL
		&& src->length >= length)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_2intlist_n_more(const t_2intlist *src,
			size_t min_a, size_t min_b)
{
	if (src != NULL
		&& is_intlist_n_more(&(src->a), min_a) == true
		&& is_intlist_n_more(&(src->b), min_b) == true)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_operator_available(e_operator operator, const t_intlist *dst)
{
	if (dst == NULL)
		return (false);
	if (operator != E_PUSH && is_intlist_n_more(dst, 2) == true)
		return (true);
	if (operator == E_PUSH && is_intlist_n_more(dst, 1) == true)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	write_operator(e_target target, e_operator operator, int show)
{
	if (show > -1 && target == E_A && operator == E_PUSH)
		write(show, "pa\n", 3);
	if (show > -1 && target == E_B && operator == E_PUSH)
		write(show, "pb\n", 3);
	if (show > -1 && target == E_A && operator == E_SWAP)
		write(show, "sa\n", 3);
	if (show > -1 && target == E_B && operator == E_SWAP)
		write(show, "sb\n", 3);
	if (show > -1 && target == E_AB && operator == E_SWAP)
		write(show, "ss\n", 3);
	if (show > -1 && target == E_A && operator == E_ROTATE)
		write(show, "ra\n", 3);
	if (show > -1 && target == E_B && operator == E_ROTATE)
		write(show, "rb\n", 3);
	if (show > -1 && target == E_AB && operator == E_ROTATE)
		write(show, "rr\n", 3);
	if (show > -1 && target == E_A && operator == E_RROTATE)
		write(show, "rra\n", 4);
	if (show > -1 && target == E_B && operator == E_RROTATE)
		write(show, "rrb\n", 4);
	if (show > -1 && target == E_AB && operator == E_RROTATE)
		write(show, "rrr\n", 4);
}

