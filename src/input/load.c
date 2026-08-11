/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:12:46 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 12:37:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

// time : O(n)
// space: O(1)
t_intnode	*load_intnode(const int *src, size_t length)
{
	t_intnode	*dst;
	t_intnode	*current;
	t_intnode	*next;
	size_t		i;

	if (src == NULL || length == 0)
		return (NULL);
	dst = init_intnode(src[0]);
	if (dst == NULL)
		return (NULL);
	current = dst;
	i = 1;
	while (i < length)
	{
		next = init_intnode(src[i]);
		if (next == NULL)
			return (dst);
		current->next = next;
		next->prev = current;
		current = next;
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
t_intlist	load_intlist(const int *src, size_t length)
{
	t_intlist	dst;
	t_intnode	*item;

	dst.length = length;
	dst.item_1st = load_intnode(src, length);
	item = dst.item_1st;
	if (item != NULL)
	{
		while (item->next != NULL)
			item = item->next;
	}
	dst.item_last = item;
	return (dst);
}

// time : O(n)
// space: O(1)
t_2intlist	load_2intlist(const int *src, size_t length)
{
	t_2intlist	dst;

	dst.b.length = 0;
	dst.b.item_1st = NULL;
	dst.b.item_last = NULL;
	dst.a = load_intlist(src, length);
	return (dst);
}
