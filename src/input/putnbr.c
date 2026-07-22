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
