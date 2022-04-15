#include "push_swap.h"

/*----------------------------------------------------------------------------*/
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*----------------------------------------------------------------------------*/
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

/*----------------------------------------------------------------------------*/
void	ft_putchar(int c)
{
	write (1, &c, 1);
}

/*----------------------------------------------------------------------------*/
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

/*----------------------------------------------------------------------------*/
/**
 * @brief Adding numbers to the end of the array of integer, the number
 * should be specified in the arguments.
 * 
 * @param stack 
 * @param num 
 */
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
/*----------------------------------------------------------------------------*/
int	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < stack->len_a)
	{
		if (!(stack -> base_a[i] < stack -> base_a[j]))
			return (1);
		i++;
		j++;
	}
	return (0);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief  Display "Error" message on the standard error
 */
void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
/*============================================================================*/

long long convert(int num)
{
	long long	bin;
	int			rem;
	int			i;
	
	bin = 0;
	rem = 1;
	i = 1;
	while (num != 0)
	{
		rem = num % 2;
		num /= 2;
		bin += rem * i;
		i *= 10;
	}
	return (bin);
}

void	positive_sort(t_stack *stack, save_t *save)
{
	int	j;

	j = 1;
	while (j < stack -> len_a)
	{
		if ((stack -> base_a[0] >> save -> m) & 1)
		{
			push_b(stack);
			rotate_b(stack);
			save -> k++;
		}
		else
			rotate_a(stack);
		j++;
	}
	if (stack -> base_a != NULL)
	{
		for (int j = 0; j < save -> k; j++)
		{
			push_a(stack);
			rotate_a(stack);;
		}
	}
}

// void negative_sort(node_t **l_a, node_t **l_b, save_t *save, int args_number)
// {
//     for (int j = 1; j <= args_number; j++) {
//         if (((*l_a)->data >> 31) & 1) {
//             push_to_list(l_a, l_b);
//             write(1, "pb ", 3);
//             save->k++;
//         }
//         else {
//             first_to_end(l_a);
//             write(1, "ra ", 3);
//         }
//     }
//     if (l_b != NULL) {
//         for (int j = 0; j < save->k; j++) {
//             push_to_list(l_b, l_a);
//             write(1, "pa ", 3);
//         }
//     }
// }


//    for (save.i = 0; save.i < 31; save.i++) {
//             save.k = 0;
//             positive_sort(&l_a, &l_b, &save, len);
//         }
//     save.k = 0;
//     negative_sort(&l_a, &l_b, &save, len);
//     write(1, "rb\n", 3);