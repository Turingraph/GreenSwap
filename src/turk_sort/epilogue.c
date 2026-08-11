/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epilogue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:22:18 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:22:19 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_sort.h"

// time : O(n)
// space: O(1)
size_t	epilogue_rotate_calculate(t_intlist *src, bool *is_sort)
{
	size_t		rotation_effect;
	t_intnode	*item;

	rotation_effect = 0;
	if (is_intlist_n_more(src, 2) == true && is_sort != NULL)
	{
		*is_sort = true;
		item = src->item_1st;
		while (item != NULL && item->next != NULL
			&& is_sort != NULL && *is_sort == true)
		{
			if (item->value > item->next->value)
				*is_sort = false;
			rotation_effect += 1;
			item = item->next;
		}
	}
	return (rotation_effect);
}

// time : O(n)
// space: O(1)
void	epilogue_rotate_action(t_2intlist *src, int show)
{
	size_t		rotation_effect;
	bool		is_sort;
	size_t		i;

	i = 0;
	if (is_2intlist_n_more(src, 2, 0) == true)
	{
		is_sort = true;
		rotation_effect = epilogue_rotate_calculate(&(src->a), &is_sort);
		while (i < rotation_effect
			&& rotation_effect <= src->a.length / 2 && is_sort == false)
		{
			action_rotate(src, show, E_A);
			i += 1;
		}
		while (i < src->a.length - rotation_effect
			&& rotation_effect > src->a.length / 2 && is_sort == false)
		{
			action_rrotate(src, show, E_A);
			i += 1;
		}
	}
}
