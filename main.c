#include "push_swap.h"
// #include "push_swap.c"
// #include "push_swap_utils.c"


int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 0;
	stack.base_a = NULL;
	stack.base_b = (int *)ft_strdup("");
	
	stack.len_a = 0;
	stack.len_b = 0;

	if (argc == 2)
		push_swap(argv[1], &stack);
	else
		printf("What???");
	return (EXIT_SUCCESS);
}

/****************************************************************
 * NOTES:
 * ==============================================================
 * you need also to handle the arguments if they are not in qutations, 
 * so if (argc > 1).
 */