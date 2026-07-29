#include"operator.h"

// time : O(1)
// space: O(1)
void	act_swap(t_intlist *src)
{
	int	temp;

	if (is_intlist_n_more(src, 2) == true)
	{
		temp = src->item_1st->value;
		src->item_1st->value = src->item_1st->next->value;
		src->item_1st->next->value = temp;
	}
}

// time : O(1)
// space: O(1)
void	act_rotate(t_intlist *src)
{
	t_intnode	*temp;

	if (is_intlist_n_more(src, 2) == true)
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
void	act_rrotate(t_intlist *src)
{
	t_intnode	*temp;

	if (is_intlist_n_more(src, 2) == true)
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
void	act_ppush(t_intlist *src, t_intlist *dst)
{
	t_intnode	*temp;

	if (is_intlist_n_more(dst, 1) == true && is_intlist_n_more(src, 1) == true)
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
void	act_push(t_intlist *src, t_intlist *dst)
{
	if (is_intlist_n_more(dst, 1) == true && is_intlist_n_more(src, 1) == true)
		act_ppush(src, dst);
	else if (is_intlist_n_more(dst, 0) == true && is_intlist_n_more(src, 1) == true)
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
}
