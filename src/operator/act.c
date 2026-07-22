#include"operator.h"

// time : O(1)
// space: O(1)
void	act_swap(t_int_list *src)
{
	int	temp;

	if (is_2_or_more(src) == true)
	{
		temp = src->item_1st->moment;
		src->item_1st->moment = src->item_1st->future->moment;
		src->item_1st->future->moment = temp;
	}
}

// time : O(1)
// space: O(1)
void	act_rotate(t_int_list *src)
{
	t_int_node	*temp;

	if (is_2_or_more(src) == true)
	{
		temp = src->item_1st;
		src->item_1st = src->item_1st->future;
		src->item_1st->flashback = NULL;
		temp->future = NULL;
		temp->flashback = src->item_last;
		src->item_last = temp;
	}
}

// time : O(1)
// space: O(1)
void	act_rrotate(t_int_list *src)
{
	t_int_node	*temp;

	if (is_2_or_more(src) == true)
	{
		temp = src->item_last;
		src->item_last = src->item_last->flashback;
		src->item_last->future = NULL;
		temp->flashback = NULL;
		temp->future = src->item_1st;
		src->item_1st = temp;
	}
}

// time : O(1)
// space: O(1)
void	act_ppush(t_int_list *src, t_int_list *dst)
{
	t_int_node	*temp;

	if (is_1_or_more(dst) == true && is_1_or_more(src) == true)
	{
		temp = src->item_1st;
		dst->item_1st->flashback = src->item_1st;
		src->item_1st = src->item_1st->future;
		if (src->item_1st != NULL)
			src->item_1st->flashback = NULL;
		temp->future = dst->item_1st;
		temp->flashback = NULL;
		dst->item_1st = dst->item_1st->flashback;
		dst->length += 1;
		src->length -= 1;
	}
}

// time : O(1)
// space: O(1)
void	act_push(t_int_list *src, t_int_list *dst)
{
	if (is_1_or_more(src) == true && dst != NULL && dst->length == 0)
	{
		dst->item_1st = src->item_1st;
		src->item_1st = src->item_1st->future;
		if (src->item_1st != NULL)
			src->item_1st->flashback = NULL;
		dst->item_1st->flashback = NULL;
		dst->item_1st->future = NULL;
		dst->item_last = dst->item_1st;
		dst->length += 1;
		src->length -= 1;
	}
	else if (is_1_or_more(src) == true && is_2_or_more(dst) == true)
		act_ppush(src, dst);
}
