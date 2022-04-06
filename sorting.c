#include "push_swap.h"

/*✅---------------------------------------------------------------------------*/
void	bubble_sort (int *base_a, int n)
{
	int	i;
	int	j;
	int	s;
	
	j = n;
	s = 1;
	while (s)
	{
		s = 0;
		i = 1;
		while (i < j)
		{
			if (base_a[i] < base_a[i - 1])
			{
				swap(&base_a[i], &base_a[i - 1]);
				s = 1;
			}
			i++;
		}
		j--;
	}
}

/*=============================================================================*/