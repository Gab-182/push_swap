/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:07:45 by gabdoush          #+#    #+#             */
/*   Updated: 2022/04/08 20:41:56 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*✅-----------------------------------------------------------*/
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*✅-----------------------------------------------------------*/
char	*ft_strcpy(char *dst, char *src)
{
	int	n;

	n = 0;
	while (src[n] != '\0')
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (dst);
}

/*✅-----------------------------------------------------------*/
void	ft_putchar(int c)
{
	write (1, &c, 1);
}

/*✅-----------------------------------------------------------*/
void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

/*✅-----------------------------------------------------------*/
void	addLast(t_stack *stack, int num)
{
	int	i;

	i = 0;
	stack -> len_a = stack -> len_a + 1;
	if (stack -> len_a >= 2)
	{
		if (stack -> len_a >= 2)
		{
			free(stack->temp_a);
			stack->temp_a = NULL;
		}
		stack->temp_a = (int *)malloc(sizeof(int) * (stack->len_a));
		while (i < stack->len_a - 1)
		{
			stack->temp_a[i] = stack->base_a[i];
			i++;
		}
		stack->temp_a[stack -> len_a - 1] = num;
		if (stack -> len_a >= 2)
		{
			free(stack->base_a);
			stack->base_a = NULL;
		}
		stack->base_a = (int *)malloc(sizeof(int) * stack->len_a);
		i = 0;
		while (i < stack->len_a)
		{
			stack->base_a[i] = stack->temp_a[i];
			i++;
		}
		if (stack->temp_a)
		{
			free(stack->temp_a);
			stack->temp_a = NULL;
		}
	}
	else
	{
		stack->base_a = (int *)malloc(sizeof(int));
		stack -> base_a[0] = num;
	}
}
/*✅-----------------------------------------------------------*/
void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
/*======================================================================*/