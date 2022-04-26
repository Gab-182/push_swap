#include "../push_swap.h"

int	small_chunks_a(int size, t_stack *stack)
{
	if (size <= 3)
	{
		handle_chunk_three_a(size, stack);
		return (0);
	}
	else if (size == 5)
	{
		handle_chunk_three_a(size, stack);
		return (0);
	}
	else
		return (1);
}

/*----------------------------------------------------------------------------*/
void	handle_chunk_three_a(int size, t_stack *stack)
{

}

/*----------------------------------------------------------------------------*/
void	handle_chunk_three_a(int size, t_stack *stack)
{

}

/*----------------------------------------------------------------------------*/