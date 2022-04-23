/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:55:52 by gabdoush          #+#    #+#             */
/*   Updated: 2022/04/23 14:12:25 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	swap_a(t_stack *stack)
{
	if (stack->len_a > 1)
		swap(&stack->base_a[0], &stack->base_a[1]);
	else
		exit(EXIT_FAILURE);
	//printf("sa\n");
	stack -> rules_number += 1;
}

/*✅-----------------------------------------------------------*/
void	swap_b(t_stack *stack)
{
	if (stack->len_b > 1)
		swap(&stack->base_b[0], &stack->base_b[1]);
	else
		exit(EXIT_FAILURE);
	//printf("sb\n");
	stack -> rules_number += 1;
}

/*✅-----------------------------------------------------------*/
void	swap_a_and_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	//printf("ss\n");
	stack -> rules_number += 1;
}

/*======================================================================*/