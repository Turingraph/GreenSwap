#include"operator.h"

// time : O(1)
// space: O(1)
void	act_swap(t_int_list *src)
{
	int	temp;

	if (is_2_or_more(src) == true)
	{
		temp = src->item_1st->value;
		src->item_1st->value = src->item_1st->next->value;
		src->item_1st->next->value = temp;
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
		src->item_1st = src->item_1st->next;
		src->item_1st->prev = NULL;
		temp->next = NULL;
		temp->prev = src->item_last;
		src->item_last->next = temp;
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
		src->item_last = src->item_last->prev;
		src->item_last->next = NULL;
		temp->prev = NULL;
		temp->next = src->item_1st;
		src->item_1st->prev = temp;
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
		dst->item_1st->prev = src->item_1st;
		src->item_1st = src->item_1st->next;
		if (src->item_1st != NULL)
			src->item_1st->prev = NULL;
		temp->next = dst->item_1st;
		temp->prev = NULL;
		dst->item_1st = dst->item_1st->prev;
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
		src->item_1st = src->item_1st->next;
		if (src->item_1st != NULL)
			src->item_1st->prev = NULL;
		dst->item_1st->prev = NULL;
		dst->item_1st->next = NULL;
		dst->item_last = dst->item_1st;
		dst->length += 1;
		src->length -= 1;
	}
	else if (is_1_or_more(src) == true && is_1_or_more(dst) == true)
		act_ppush(src, dst);
}
