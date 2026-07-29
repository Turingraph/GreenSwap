#include"operator.h"

// time : O(1)
// space: O(1)
size_t	action_swap(t_2intlist *src, int show, e_target target)
{
	size_t	y;

	y = write_available_operator(src, target, show, E_SWAP);
	operate_2intlist(src, target, E_SWAP, act_swap);
	return (y);
}

// time : O(1)
// space: O(1)
size_t	action_rotate(t_2intlist *src, int show, e_target target)
{
	size_t	y;

	y = write_available_operator(src, target, show, E_ROTATE);
	operate_2intlist(src, target, E_ROTATE, act_rotate);
	return (y);
}

// time : O(1)
// space: O(1)
size_t	action_rrotate(t_2intlist *src, int show, e_target target)
{
	size_t	y;

	y = write_available_operator(src, target, show, E_RROTATE);
	operate_2intlist(src, target, E_RROTATE, act_rrotate);
	return (y);
}

// time : O(1)
// space: O(1)
size_t	action_push(t_2intlist *src, int show, e_target target)
{
	size_t	y;

	y = write_available_operator(src, target, show, E_PUSH);
	operate_2intlist(src, target, E_PUSH, NULL);
	return (y);
}


