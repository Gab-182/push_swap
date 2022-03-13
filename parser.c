#include "push_swap.h"

void	check_nigative(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (ft_isdigit(str[i + 1]) == 1)
				break ;
			else
			{
				ft_putstr("ERROR\n");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}
/*✅-----------------------------------------------------------*/
void	check_digit(char **str)
{
	int	i;

	i = 0;
	while (str[i] && str)
	{
		//check_nigative(str[i]);
		printf("*str[i] --> %c\n", *str[i]);
		printf("*(str[i + 1]) --> %c\n", *(str[i + 1]));



		if (*str[i] && str[i] && (*str[i] == '-' || *str[i] == '+'))
		{
			i++;
			if (*str[i] && ft_isdigit(*str[i]) == 1)
				i++;
			else
			{
				ft_putstr("ERROR\n");
				exit(EXIT_FAILURE);
			}
		}


		if (ft_isdigit(*str[i]) != 1 )
		{
			ft_putstr("ERROR\n");
			free(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/*✅-----------------------------------------------------------*/
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
				ft_putstr("ERROR\n");
				free(stack->base_a);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

/*✅-----------------------------------------------------------*/
void	check_digit_multi(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (ft_isdigit(str[i + 1]) == 1)
				i++;
			else
			{
				ft_putstr("ERROR\n");
				exit(EXIT_FAILURE);
			}
		}
		while (str[i] == ' ' && str[i])
			i++;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
		{
			ft_putstr("ERROR\n");
			exit(EXIT_FAILURE);
		}
	}
}

/*✅-----------------------------------------------------------*/
void	check_empty(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		else
			break ;
	}
	if (i == ft_strlen(arg))
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
}

/*✅-----------------------------------------------------------*/
void	check_length(char *arg)
{
	if (ft_strlen(arg) == 0)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
}

/*======================================================================*/