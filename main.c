/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:26 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/10 03:48:51 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*✅-------------------------------------------------------------------------*/
/**
 ** @brief the main part of the sort algorithem, it handle all of the sizes
 ** @param size 
 ** @param stack 
 **/
void	sort(int size, t_stack *stack)
{
	int	chunk_count_in_b;

	chunk_count_in_b = 0;
	if (is_sorted(stack) == 1)
	{
		if (stack -> len_a == 2)
			sort_2_a(stack);
		else if (stack -> len_a == 3)
			sort_chunk_3_a(3, stack);
		else if (stack -> len_a == 4)
			sort_4_a(4, stack);
		else if (stack -> len_a == 5)
			sort_5_a(5, stack);
		else if (stack -> len_a > 5)
			push_a_to_b(size, stack, &chunk_count_in_b);
	}
	else
	{
		free(stack -> base_a);
		exit (0);
	}
}

/*✅-------------------------------------------------------------------------*/
int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.base_a = NULL;
	stack.base_b = NULL;
	stack.len_a = 0;
	stack.len_b = 0;
	if (argc == 2)
	{
		push_swap(argv[1], &stack);
		free_stack(stack.base_a, 'n');
		free_stack(stack.base_b, 'n');
	}
	else if (argc > 2)
	{
		argv++;
		push_swap_multi(argv, &stack);
		checking_duplicated(&stack);
		sort(stack.len_a, &stack);
		free_stack(stack.base_a, 'n');
		free_stack(stack.base_b, 'n');
	}
	return (EXIT_SUCCESS);
}

/*============================================================================*/