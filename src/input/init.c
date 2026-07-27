#include"input.h"

// time : O(1)
// space: O(1)
void	free_intnode(t_intnode *src)
{
	t_intnode	*temp;

	while (src != NULL)
	{
		temp = src->next;
		free(src);
		src = temp;
	}
}

// time : O(n)
// space: O(1)
void	free_intlist(t_intlist *src)
{
	if (src != NULL)
	{
		free_intnode(src->item_1st);
		src->item_1st = NULL;
		src->item_last = NULL;
		src->length = 0;
	}
}

// time : O(n)
// space: O(1)
void	free_2intlist(t_2intlist *src)
{
	if (src != NULL)
	{
		free_intlist(&(src->a));
		free_intlist(&(src->b));
	}
}

// time : O(1)
// space: O(1)
t_intnode	*init_intnode(int src)
{
	t_intnode	*dst;

	dst = (t_intnode *)malloc(sizeof(t_intnode));
	if (dst == NULL)
		return (NULL);
	dst->prev = NULL;
	dst->value = src;
	dst->next = NULL;
	return (dst);
}


