#include "../push_swap.h"


/*============================================================================*/
void	bubble_sort_5(int *chunk)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < 5) 
	{
		j = 0;
		while (j < 5 - i - 1)
		{
			if (chunk[j] > chunk[j + 1])
			{
				temp = chunk[j];
				chunk[j] = chunk[j + 1];
				chunk[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*----------------------------------------------------------------------------*/
int	get_middle_num_five_b(t_stack *stack)
{
	int	i;

	i = 0;
	stack -> temp_b = malloc(sizeof(int) * 5);
	if (!(stack -> temp_b))
		return (0);
	while (i < 5)
	{
		stack -> temp_b[i] = stack -> base_b[i];
		i++;
	}
	bubble_sort_5(stack -> temp_b);
	stack -> middle_num = stack -> temp_b[2];
	free(stack -> temp_b);
	return (stack -> middle_num);
}

/*----------------------------------------------------------------------------*/
void	sort_chunk_5_b(int size, t_stack *stack)
{
	int	middle_num;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	middle_num = get_middle_num_five_b(stack);
	while (size--)
	{
		if (stack -> base_b[0] >= middle_num)
		{
			push_a(stack);
			ft_putstr("pa\n");
			push++;
		}
		else
		{
			rotate_b(stack);
			ft_putstr("rb\n");
			rotate++;
		}
		// i am sopping here so i can use sort 3 nums function.
		if (push == 3)
			break ;
	}
	while (rotate--)
	{
		reverse_rotate_b(stack);
		ft_putstr("rrb\n");
	}
	// I changed some thing in this function so fiqure it out.
	sort_chunk_3_a(3, stack);
	sort_2_b(stack);
}

/*============================================================================*/