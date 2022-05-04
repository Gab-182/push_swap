#include "../push_swap.h"

/*✅-----------------------------------------------------------*/
void	rotate_a(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack -> temp_a = malloc(sizeof(int) * stack -> len_a);
	if (!stack -> temp_a)
		free_stack(stack -> temp_a, 'e');
	while (i < stack -> len_a)
	{
		stack->temp_a[j] = stack -> base_a[i];
		i++;
		j++;
	}
	stack -> temp_a[stack->len_a - 1] = stack->base_a[0];
	free_stack(stack -> base_a, 'n');
	stack -> base_a = malloc(sizeof(int) * stack -> len_a);
	if (!stack -> base_a)
		free_stack(stack -> base_a, 'e');
	ft_stack_cpy(stack -> base_a, stack -> temp_a, stack -> len_a);
	free_stack(stack -> temp_a, 'n');
}

/*✅-----------------------------------------------------------*/
void	rotate_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->temp_b = malloc(sizeof(int) * stack->len_b);
	while (i < stack->len_b)
	{
		stack->temp_b[j] = stack->base_b[i];
		i++;
		j++;
	}
	stack->temp_b[stack->len_b - 1] = stack->base_b[0];
	if (stack->len_b > 0)
		free(stack->base_b);
	stack->base_b = malloc(sizeof(int) * stack->len_b);
	i = 0;
	while (i < stack->len_b)
	{
		stack->base_b[i] = stack->temp_b[i];
		i++;
	}
	free(stack->temp_b);
}

/*✅-----------------------------------------------------------*/
void	rotate_a_b(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

/*======================================================================*/