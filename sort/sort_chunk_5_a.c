#include "../push_swap.h"


/*============================================================================*/
void	bubble_sort_a(int *chunk, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size) 
	{
		j = 0;
		while (j < size - i - 1)
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
int	get_middle_num_five_a(int size, t_stack *stack)
{
	int	middle_num;
	int	i;

	i = 0;
	
	if (size == 5)
	{
		stack -> temp_a = (int *)malloc(sizeof(int) * size);
		while (i <= size)
		{
			stack -> temp_a[i] = stack -> base_a[i];
			i++;
		}
		bubble_sort_a(stack -> temp_a, size);
		middle_num = stack -> temp_a[2];
		free(stack -> temp_a);
	}
	return (middle_num);
}

/*----------------------------------------------------------------------------*/
void	sort_five_a(int size, t_stack *stack)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_middle_num_five_a(size, stack);
	while (size--)
	{
		if (stack -> base_a[0] < mid)
		{
			push_b(stack);
			push++;
		}
		else
		{
			rotate_a(stack);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		reverse_rotate_a(stack);
}

/*----------------------------------------------------------------------------*/
void		sort_chunk_5_a(int size, t_stack *stack)
{
	sort_five_a(size, stack);
	sort_chunk_3_a(3, stack);
	sort_2_b(stack);
}

/*============================================================================*/