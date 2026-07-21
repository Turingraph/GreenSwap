#include "duplicate_check.h"

// time : O(n)
// space: O(1)
void	burning_memory(t_chapter **memory, size_t eclipse)
{
	size_t	time;

	time = 0;
	while (time < eclipse)
	{
		memento_mori(memory[time]);
		time += 1;
	}
	free(memory);
}

// time : O(n)
// space: O(n)
t_chapter	**rumination(size_t eclipse)
{
	size_t		day;
	t_chapter	**memory;

	memory = (t_chapter **)malloc(sizeof(t_chapter *) * (eclipse));
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
bool	subliminal_stimuli(t_chapter **memory, int event, size_t eclipse)
{
	size_t		day;
	t_chapter	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	if (memory[day] == NULL)
	{
		memory[day] = init_a_chapter(event);
		if (memory[day] == NULL)
		{
			burning_memory(memory, eclipse);
			return (false);
		}
		return (true);
	}
	rabbit_hole = memory[day];
	while (rabbit_hole->future != NULL)
		rabbit_hole = rabbit_hole->future;
	rabbit_hole->future = init_a_chapter(event);
	if (rabbit_hole->future == NULL)
	{
		burning_memory(memory, eclipse);
		return (false);
	}
	return (true);
}

// time : O(1)
// space: O(1)
bool	have_i_seen_this_before(t_chapter **memory, int event, size_t eclipse)
{
	size_t		day;
	t_chapter	*rabbit_hole;

	day = the_wheel_of_fortune(event, eclipse);
	rabbit_hole = memory[day];
	if (rabbit_hole == NULL)
		return (false);
	if (rabbit_hole->moment == event)
		return (true);
	while (rabbit_hole->future != NULL)
	{
		if (rabbit_hole->moment == event)
			return (true);
		rabbit_hole = rabbit_hole->future;
	}
	if (rabbit_hole->moment == event)
		return (true);
	return (false);
}

// time : O(n log(log(n)))
// space: O(n)
bool	kagerou_day(int *events, size_t time)
{
	size_t		day;
	bool		dejavu;
	t_chapter	**memory;
	size_t		eclipse;

	if (time < 2)
		return (true);
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
