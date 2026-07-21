#include"input.h"

// time : O(1)
// space: O(1)
void	free_future(t_chapter *src, bool future_is_wild)
{
	t_chapter	temp;

	while (src != NULL)
	{
		if (future_is_wild == true)
			temp = *(src->future);
		else
			temp = *(src->flashback);
		free(src);
		*src = temp;
	}
}

// time : O(1)
// space: O(1)
void	memento_mori(t_chapter *src)
{
	t_chapter	*future;

	future = NULL;
	if (src != NULL)
		future = src->future;
	free_future(src, false);
	free_future(future, true);
	free(src);
}

// time : O(n)
// space: O(1)
void	free_int_list(t_int_list *src)
{
	if (src != NULL)
	{
		memento_mori(src->item_1st);
		memento_mori(src->item_last);
		src->item_1st = NULL;
		src->item_last = NULL;
		src->length = 0;
	}
}

// time : O(n)
// space: O(1)
void	free_green_swap(t_green_swap *src)
{
	if (src != NULL)
	{
		free_int_list(&(src->a));
		free_int_list(&(src->b));
	}
}

// time : O(1)
// space: O(1)
t_chapter	*init_a_chapter(int src)
{
	t_chapter	*dst;

	dst = (t_chapter *)malloc(sizeof(t_chapter));
	if (dst == NULL)
		return (NULL);
	dst->flashback = NULL;
	dst->moment = src;
	dst->future = NULL;
	return (dst);
}


