/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:14:33 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/08 16:53:17 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*============================================================================*/
void	swap_a(t_stack *stack)
{
	int	*temp;

	temp = malloc((2 + 1) * sizeof(int *));
	temp[0] = stack->base_a[0];
	temp[1] = stack->base_a[1];
	stack->base_a[1] = temp[0];
	stack->base_a[0] = temp[1];
	free(temp);
	write(1, "sa\n", 3);
}

/*✅--------------------------------------------------------------------------*/
void	swap_b(t_stack *stack)
{
	int		*temp;

	temp = malloc((2 + 1) * sizeof(int *));
	temp[0] = stack->base_b[0];
	temp[1] = stack->base_b[1];
	stack->base_b[1] = temp[0];
	stack->base_b[0] = temp[1];
	free(temp);
	write(1, "sb\n", 3);
}

/*✅--------------------------------------------------------------------------*/
void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	write(1, "rrr\n", 4);
}

/*✅--------------------------------------------------------------------------*/
void	reverse_rotate_a(t_stack *stack)
{
	reverse_rotate(stack->base_a, stack->len_a);
}

/*✅--------------------------------------------------------------------------*/
void	reverse_rotate_b(t_stack *stack)
{
	reverse_rotate(stack->base_b, stack->len_b);
}
/*============================================================================*/