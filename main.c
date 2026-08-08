#include "src/dejavu/dejavu.h"
#include "src/turk_sort/turk_sort.h"

int	*split_int(char *input, size_t arr_length)
{
	char	**str;
	int		*dst;

	if (arr_length == 0)
		return (NULL);
	str = f_split(input, " \n\t\r\f\v");
	if (str == NULL)
		return (NULL);
	dst = strarr_to_intarr((const char **)str, arr_length);
	free_2d_arr((void **)str, arr_length);
	return (dst);
}

int	main(int len, char **input)
{
	int			*src;
	t_2intlist	intlist;
	size_t		arr_length;

	if (len < 2)
		return (0);
	arr_length = f_split_len(input[1], "\n\t\r\f\v ");
	if (len == 2)
		src = split_int(input[1], arr_length);
	else
		arr_length = len - 1;
	if (len > 2)
		src = strarr_to_intarr((const char **)(input + 1), arr_length);
	if (src == NULL || kagerou_day(src, arr_length) == true)
	{
		write(2, "Error\n", 6);
		free(src);
		exit(1);
	}
	intlist = load_2intlist(src, arr_length);
	if (is_intlist_sort(intlist.a.item_1st, true, 0) == false)
		turk_sort(&intlist, 1);
	free_2intlist(&intlist);
	free(src);
	return (0);
}

	// write_intlist(intlist.a.item_1st, true, "output: ");
	// write_intlist(intlist.b.item_1st, true, "output: ");

/*
valgrind --leak-check=full --show-leak-kinds=all ./push_swap "2 1 3 6 5 44"


-------------------------------------------------------------


                  Order nums

-------------------------------------------------------------

1. [OK][MOK] 
2. [KO][MOK] 
3. [OK][MOK] 
4. [OK][MOK] 
5. [KO][MOK] 
6. [OK][MOK] 
7. [KO][MOK] 
8. [OK][MOK] 
Error
9. [OK]Error
[MOK] 
Error
10. [OK]Error
[MOK] 
11. [KO][MOK] 
12. [KO][MOK] 

-------------------------------------------------------------


                  Random test with big nums

-------------------------------------------------------------

Error
[OK][5/5]Error
 [KO]
Error
[OK][5/5]Error
 [KO]
[OK][5/5] [OK]

*/
