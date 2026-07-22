#include"test_helper.h"

// time : O(n)
// space: O(1)
void	write_future(t_int_node *dst, bool is_future)
{
	t_int_node	*temp;

	temp = dst;
	write(1, ">>> ", 4);
	while (temp != NULL)
	{
		ft_putnbr_fd(temp->moment, 1, "0123456789", 1);
		write(1, ", ", 2);
		if (is_future == true)
			temp = temp->future;
		else
			temp = temp->flashback;
	}
	write(1, "\n", 1);
}

// time : O(1)
// space: O(1)
void	write_total_score(size_t score, size_t max_score)
{
	write(1, "Score: ", 8);
	ft_putnbr_fd((int)score, 1, "0123456789", 1);
	write(1, " / ", 3);
	ft_putnbr_fd((int)max_score, 1, "0123456789", 1);
	write(1, "\n", 1);
}

// time : O(n)
// space: O(1)
int	compare_intarr(const int *str_1, const int *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (0);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (-1);
	while (i < n - 1 && *str_1 == *str_2)
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
	}
	return (*str_1 - *str_2);
}

// time : O(n)
// space: O(1)
bool	compare_intarr_with_list(const int *intarr, const t_int_node *intlist, size_t length, bool future_is_wild)
{
	size_t	i;

	if (intarr == NULL && intlist == NULL)
		return (true);
	if (intarr == NULL || intlist == NULL)
		return (false);
	i = 0;
	while (i < length && intlist != NULL)
	{
		if (intlist->moment != intarr[i] && future_is_wild == true)
			return (false);
		if (intlist->moment != intarr[length - i - 1] && future_is_wild == false)
			return (false);
		if (future_is_wild == true)
			intlist = intlist->future;
		else
			intlist = intlist->flashback;
		i += 1;
	}
	if (i < length && intlist == NULL)
		return (false);
	return (true);
}

