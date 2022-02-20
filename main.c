/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:05:43 by gabdoush          #+#    #+#             */
/*   Updated: 2022/02/20 12:34:03 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.base_a = NULL;
	stack.base_b = (int *)ft_strdup("");
	stack.len_a = 0;
	stack.len_b = 0;
	if (argc == 2)
		push_swap(argv[1], &stack);
	else if(argc > 2)
	{
		/* to move after {./push_swap} */
		// argv++;
		// push_swap(*argv, &stack);
		int i = 0;
		while (argv[i] != NULL)
		{
			printf("argv[%d] --> %s\n" , i, argv[i]);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

/****************************************************************
 * NOTES:
 * ==============================================================
 * you need also to handle the arguments if they are not in qutations, 
 * so if (argc > 1).
 */