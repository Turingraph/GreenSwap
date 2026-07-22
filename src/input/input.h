#ifndef INPUT_H
# define INPUT_H

#include"stdlib.h"
#include"stdbool.h"
#include"unistd.h"

typedef struct t_int_node t_int_node;

typedef struct t_int_node
{
	int					moment;
	struct t_int_node	*future;
	struct t_int_node	*flashback;
}	t_int_node;

typedef struct t_int_list t_int_list;

typedef struct t_int_list
{
	struct t_int_node	*item_1st;
	struct t_int_node	*item_last;
	size_t				length;
}	t_int_list;

typedef struct t_green_swap t_green_swap;

typedef struct t_green_swap
{
	struct t_int_list	a;
	struct t_int_list	b;
}	t_green_swap;

// atoi.c
size_t			f_strlen(const char *str);
int				f_atoi(const char *src, bool *is_int, const char *base, size_t digits);

// init.c
t_int_node			*init_a_node(int src);
void			memento_mori(t_int_node *src);
void			free_int_list(t_int_list *src);
void			free_green_swap(t_green_swap *src);

// load.c
void	free_2d_arr(void **arr, size_t len);
char	**copy_strarr(const char **src, size_t length);
int				*strarr_to_intarr(const char **src, size_t length);
t_int_node			*intarr_to_node(const int *src, size_t length);
t_int_list		intarr_to_intlist(const int *src, size_t length);
t_green_swap	intarr_to_green_swap(const int *src, size_t length);

// putnbr.c
size_t			ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

#endif
