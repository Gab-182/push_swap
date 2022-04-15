#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	save_t save;
	int i;

	i = 0;

	stack.base_a = NULL;
	stack.base_b = (int *)ft_strdup("");
	stack.len_a = 0;
	stack.len_b = 0;
	if (argc == 2)
		push_swap(argv[1], &stack, &save);
	else if(argc > 2)
	{
		argv++;
		push_swap_multi(argv, &stack, i, &save);
	}
	return (EXIT_SUCCESS);
}
