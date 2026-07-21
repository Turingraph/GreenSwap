#ifndef INPUT_H
# define INPUT_H

#include"stdlib.h"
#include"stdbool.h"

typedef struct t_chapter;

typedef struct t_chapter
{
	int					moment;
	struct t_chapter	*future;
	struct t_chapter	*flashback;
}	t_chapter;

typedef struct t_int_list t_int_list;

typedef struct t_int_list
{
	struct t_chapter	*item_1st;
	struct t_chapter	*item_last;
	size_t				length;
}	t_int_list;

typedef struct t_green_swap t_green_swap;

typedef struct t_green_swap
{
	struct t_int_list	a;
	struct t_int_list	b;
}	t_green_swap;

// atoi.c
int			f_atoi(const char *src, bool *is_int, const char *base, size_t digits);
size_t		ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// init.c
t_chapter	*init_a_chapter(int src);
void		memento_mori(t_chapter *src);
void		free_int_list(t_int_list *src);
void		free_green_swap(t_green_swap *src);

// load.c
int				*strarr_to_intarr(const char **src, size_t length);
t_chapter		*intarr_to_chapter(const int *src, size_t length);
t_int_list		intarr_to_intlist(const int *src, size_t length);
t_green_swap	intarr_to_green_swap(const int *src, size_t length);

#endif
