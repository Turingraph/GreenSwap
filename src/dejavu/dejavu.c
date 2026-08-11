/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dejavu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 11:09:08 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/11 11:09:09 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dejavu.h"

// time : O(n)
// space: O(1)
void	burning_memory(t_intnode **memory, size_t eclipse)
{
	size_t	time;

	time = 0;
	while (time < eclipse)
	{
		free_intnode(memory[time]);
		time += 1;
	}
	free(memory);
}

// time : O(n)
// space: O(n)
t_intnode	**rumination(size_t eclipse)
{
	size_t		day;
	t_intnode	**memory;

	memory = (t_intnode **)malloc(sizeof(t_intnode *) * (eclipse));
	if (memory == NULL)
		return (NULL);
	day = 0;
	while (day < eclipse)
	{
		memory[day] = NULL;
		day += 1;
	}
	return (memory);
}

// time : O(1)
// space: O(1)
bool	subliminal_stimuli(t_intnode **memory, int event, size_t eclipse)
{
	size_t		day;
	t_intnode	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	if (memory[day] == NULL)
	{
		memory[day] = init_intnode(event);
		if (memory[day] == NULL)
		{
			burning_memory(memory, eclipse);
			return (false);
		}
		return (true);
	}
	rabbit_hole = init_intnode(event);
	if (rabbit_hole == NULL)
	{
		burning_memory(memory, eclipse);
		return (false);
	}
	rabbit_hole->next = memory[day];
	memory[day] = rabbit_hole;
	return (true);
}

// time : O(1)
// space: O(1)
bool	have_i_seen_this_before(t_intnode **memory, int event, size_t eclipse)
{
	size_t		day;
	t_intnode	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	rabbit_hole = memory[day];
	if (rabbit_hole == NULL)
		return (false);
	if (rabbit_hole->value == event)
		return (true);
	while (rabbit_hole->next != NULL)
	{
		if (rabbit_hole->value == event)
			return (true);
		rabbit_hole = rabbit_hole->next;
	}
	if (rabbit_hole->value == event)
		return (true);
	return (false);
}

// time : O(n log(log(n)))
// space: O(n)
bool	kagerou_day(int *events, size_t time)
{
	size_t		day;
	bool		dejavu;
	t_intnode	**memory;
	size_t		eclipse;

	if (time < 2)
		return (false);
	dejavu = false;
	eclipse = wait_next_eclipse(time);
	if (eclipse == 0)
		return (true);
	memory = rumination(eclipse);
	if (memory == NULL)
		return (true);
	day = 0;
	while (day < time && dejavu == false)
	{
		if (have_i_seen_this_before(memory, events[day], eclipse) == true)
			dejavu = true;
		if (subliminal_stimuli(memory, events[day], eclipse) == false)
			day = time;
		day += 1;
	}
	burning_memory(memory, eclipse);
	return (dejavu);
}
