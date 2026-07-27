#include"input.h"

// time : O(1)
// space: O(1)
size_t	display_int(int fd, long x, const char *base, bool is_write)
{
	size_t	i;
	long	d;
	char	coef;
	size_t	len;

	if (base == NULL)
		return (0);
	i = 0;
	len = f_strlen(base);
	d = 1;
	while (d < x)
		d *= len;
	if (d > x)
		d /= len;
	while (d > 0)
	{
		coef = base[x / d];
		if (is_write == true)
			write(fd, &coef, 1);
		x = x % d;
		d /= len;
		i += 1;
	}
	return (i);
}

// time : O(1)
// space: O(1)
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits)
{
	size_t	i;
	size_t	j;

	if (base != NULL)
	{
		i = 0;
		j = 0;
		if (n > 0)
			j = display_int(fd, (long)n, base, 0);
		else if (n < 0)
		{
			n *= -1;
			j = display_int(fd, n, base, 0);
			i += (size_t)write(fd, "-", 1);
		}
		if (j > digits)
			j = digits;
		while (i < digits - j)
			i += (size_t)write(fd, base, 1);
		if (n != 0)
			i += display_int(fd, n, base, 1);
		return (i);
	}
	return (0);
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
bool	is_2intarr_same(const int *str_1, const int *str_2, size_t n)
{
	size_t	i;

	i = 0;
	if (str_1 == NULL && str_2 == NULL)
		return (true);
	if ((str_1 == NULL && str_2 != NULL) || (str_1 != NULL && str_2 == NULL))
		return (false);
	while (i < n - 1 && *str_1 == *str_2)
	{
		i += 1;
		str_1 += 1;
		str_2 += 1;
	}
	if (*str_1 - *str_2 == 0)
		return (true);
	return (false);
}

// time : O(n)
// space: O(1)
bool	is_intarr_and_list_same(const int *intarr, const t_intnode *intlist, size_t length, bool future_is_wild)
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
