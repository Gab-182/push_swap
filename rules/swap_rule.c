/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:55:52 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/05 15:20:55 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	swap_a(t_stack *stack)
{
	write(1, "sa\n", 3);
	if (stack->len_a > 1)
		swap(&stack->base_a[0], &stack->base_a[1]);
	else
		exit(EXIT_FAILURE);
}

/*✅-----------------------------------------------------------*/
void	swap_b(t_stack *stack)
{
	write(1, "sb\n", 3);
	if (stack->len_b > 1)
		swap(&stack->base_b[0], &stack->base_b[1]);
	else
		exit(EXIT_FAILURE);
}

// /*✅-----------------------------------------------------------*/
// void	swap_a_and_b(t_stack *stack)
// {
// 	swap_a(stack);
// 	swap_b(stack);
// }

/*======================================================================*/