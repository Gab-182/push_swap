/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:13:04 by gabdoush          #+#    #+#             */
/*   Updated: 2022/05/07 19:49:59 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(int *tab, int size)
{
	int	swap;
	int	i;

	i = 1;
	while (i < size)
	{
		swap = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = swap;
		i++;
	}
}

/*----------------------------------------------------------------------------*/
void	rotate_a(t_stack *stack)
{
	rotate(stack->base_a, stack->len_a);
}

/*----------------------------------------------------------------------------*/
void	rotate_b(t_stack *stack)
{
	rotate(stack->base_b, stack->len_b);
}

/*----------------------------------------------------------------------------*/
void	reverse_rotate(int *tab, int size)
{
	int	i;
	int	swap;

	i = size - 1;
	while (i > 0)
	{
		swap = tab[i];
		tab[i] = tab[i - 1];
		tab[i - 1] = swap;
		i--;
	}
}

/*----------------------------------------------------------------------------*/
void	reverse_rotate_a(t_stack *stack)
{
	reverse_rotate(stack->base_a, stack->len_a);
}

/*----------------------------------------------------------------------------*/
void	reverse_rotate_b(t_stack *stack)
{
	reverse_rotate(stack->base_b, stack->len_b);
}

/*----------------------------------------------------------------------------*/
void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}
/*----------------------------------------------------------------------------*/
void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
/*----------------------------------------------------------------------------*/