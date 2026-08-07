#include "src/dejavu/dejavu.h"
#include "src/turk_sort/turk_sort.h"

int	main(int len, char **input)
{
	int			*src;
	t_2intlist	intlist;
	char		**str;
	size_t		arr_length;

	if (len < 2)
		return (0);
	arr_length = f_split_len(input[1], "\n\t\r\f\v ");
	if (len == 2 && arr_length > 0)
	{
		str = f_split(input[1], " \n\t\r\f\v");
		if (str == NULL)
			return (0);
		src = strarr_to_intarr((const char **)str, arr_length);
		free_2d_arr((void **)str, arr_length);
	}
	else
	{
		arr_length = len - 1;
		src = strarr_to_intarr((const char **)(input + 1), arr_length);
	}
	if (src == NULL || kagerou_day(src, arr_length) == true)
	{
		write(2, "Error\n", 6);
		free(src);
		exit(1);
	}
	intlist = load_2intlist(src, arr_length);
	turk_sort(&intlist, 1);
	free_2intlist(&intlist);
	free(src);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./push_swap "2 1 3 6 5 44"
*/