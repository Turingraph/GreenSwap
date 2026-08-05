#include "input.h"

int	main(void)
{
	size_t			col = 15;
	size_t			score;
	size_t			max_score = 6;
	size_t			i;
	int				*dst;
	t_2intlist	intlist;
	char			*strarr[][15] = {
		{"64",	"98",	"12",	"10",	"73",	"56",	"39",	"40",	"53",	"42",	"95",	"21",	"31",	"60",	"19"},
		{"89",	"78",	"69",	"42",	"24",	"59",	"81",	"96",	"19",	"87",	"15",	"80",	"98",	"63",	"98"},
		{"74",	"47",	"70",	"27",	"96",	"79",	"20",	"97",	"93",	"70",	"93",	"88",	"20",	"15",	"78"},
		{"21",	"34",	"71",	"59",	"61",	"41",	"72",	"80",	"36",	"13",	"17",	"79",	"90",	"73",	"57"},
		{"27",	"85",	"14",	"88",	"95",	"33",	"68",	"68",	"52",	"39",	"70",	"83",	"10",	"12",	"95"},
		{"44",	"26",	"10",	"47",	"54",	"24",	"12",	"32",	"57",	"50",	"19",	"40",	"15",	"42",	"96"},
	};
	int			intarr[][15] = {
		{64,	98,	12,	10,	73,	56,	39,	40,	53,	42,	95,	21,	31,	60,	19},
		{89,	78,	69,	42,	24,	59,	81,	96,	19,	87,	15,	80,	98,	63,	98},
		{74,	47,	70,	27,	96,	79,	20,	97,	93,	70,	93,	88,	20,	15,	78},
		{21,	34,	71,	59,	61,	41,	72,	80,	36,	13,	17,	79,	90,	73,	57},
		{27,	85,	14,	88,	95,	33,	68,	68,	52,	39,	70,	83,	10,	12,	95},
		{44,	26,	10,	47,	54,	24,	12,	32,	57,	50,	19,	40,	15,	42,	96},
	};

	score = 0;
	i = 0;
	while (i < max_score)
	{
		dst = strarr_to_intarr((const char **)strarr[i], col);
		intlist = load_2intlist(dst, col);
		if (intlist.b.item_1st == NULL && intlist.b.item_last == NULL
			&& is_intarr_and_list_same(intarr[i], intlist.a.item_1st, col, true) == true
			&& is_intarr_and_list_same(intarr[i], intlist.a.item_last, col, false) == true)
			score += 1;
		free(dst);
		free_2intlist(&intlist);
		i += 1;
	}
	write_total_score(score, max_score);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/input/load_push_swap.out
*/

