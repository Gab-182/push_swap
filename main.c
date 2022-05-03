/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:15:26 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/03 16:15:27 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.base_a = NULL;
	stack.base_b = NULL;
	stack.len_a = 0;
	stack.len_b = 0;
	if (argc == 2)
		push_swap(argv[1], &stack);
	else if(argc > 2)
	{
		argv++;
		push_swap_multi(argv, &stack);
	}
	return (EXIT_SUCCESS);
}
 