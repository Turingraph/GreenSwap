#include"input.h"

// time : O(1)
// space: O(1)
void	free_int_node(t_int_node *src)
{
	t_int_node	*temp;

	while (src != NULL)
	{
		temp = src->next;
		free(src);
		src = temp;
	}
}

// time : O(n)
// space: O(1)
void	free_int_list(t_int_list *src)
{
	if (src != NULL)
	{
		free_int_node(src->item_1st);
		src->item_1st = NULL;
		src->item_last = NULL;
		src->length = 0;
	}
}

// time : O(n)
// space: O(1)
void	free_double_int_list(t_double_int_list *src)
{
	if (src != NULL)
	{
		free_int_list(&(src->a));
		free_int_list(&(src->b));
	}
}

// time : O(1)
// space: O(1)
t_int_node	*init_a_node(int src)
{
	t_int_node	*dst;

	dst = (t_int_node *)malloc(sizeof(t_int_node));
	if (dst == NULL)
		return (NULL);
	dst->prev = NULL;
	dst->value = src;
	dst->next = NULL;
	return (dst);
}


