#include "push_swap.h"

/*------------------------------------------------------*/
void		check_digit(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_isdigit(*str[i]) != 1)
		{
			ft_putstr("ERROR 123\n");
			free(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/*------------------------------------------------------*/
void	checking_duplicated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->len_a)
	{
		
		while (j < stack->len_a)
		{
			if (stack->base_a[i] == stack->base_a[j])
			{
				ft_putstr("ERROR ....\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}