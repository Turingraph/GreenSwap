/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:05:01 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:05:15 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

// time : O(n)
// space: O(1)
bool	is_intarr_and_list_same(const int *intarr,
	const t_intnode *intlist, size_t length, bool future_is_wild)
{
	size_t	i;

	if (intarr == NULL && intlist == NULL)
		return (true);
	if (intarr == NULL || intlist == NULL)
		return (false);
	i = 0;
	while (i < length && intlist != NULL)
	{
		if (intlist->value != intarr[i] && future_is_wild == true)
			return (false);
		if (intlist->value != intarr[length - i - 1] && future_is_wild == false)
			return (false);
		if (future_is_wild == true)
			intlist = intlist->next;
		else
			intlist = intlist->prev;
		i += 1;
	}
	if (i < length && intlist == NULL)
		return (false);
	return (true);
}

// time : O(n)
// space: O(1)
void	write_intlist(t_intnode *src, bool is_future, char *str)
{
	t_intnode	*temp;

	temp = src;
	if (str != NULL || str[0] != '\0')
		write(1, str, f_strlen(str));
	while (temp != NULL)
	{
		ft_putnbr_fd(temp->value, 1, "0123456789", 1);
		write(1, ", ", 2);
		if (is_future == true)
			temp = temp->next;
		else
			temp = temp->prev;
	}
	write(1, "\n", 1);
}

// time : O(n)
// space: O(1)
bool	is_intlist_sort(const t_intnode *src, int ascending, size_t tolerate)
{
	size_t	i;

	i = 0;
	while (src != NULL && src->next != NULL && i <= tolerate)
	{
		if (src->value * ascending > src->next->value * ascending)
			i += 1;
		src = src->next;
	}
	if (i > tolerate)
		return (false);
	return (true);
}
