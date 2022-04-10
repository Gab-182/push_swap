#include "push_swap.h"

int	isNumber(char *str)
{
	int	i;

	i = 0;
	while (str[i]!= '\0')
	{

		if (ft_isdigit(str[i]) == 0 || str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

/*✅-----------------------------------------------------------*/
void	check_digit(char **str)
{
	int	i;

	i = 0;
	while (str[i] && str)
	{
		if (str[i][0] == '-' || str[i][0] == '+')
		{
			if (str[i] && str && str[i][1] && ft_isdigit(str[i][1]) == 1)
			{
				if (str[i + 1] == NULL)
					return ;
				i++;
			}
			else
				error();
		}
		else if (isNumber(str[i]) != 1)
			error();
		else if (ft_isdigit(*str[i]) != 1)
		{
			free(str);
			error();
		}
		else
			i++;
	}
	return ;
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
			if (stack->base_a[i] == stack->base_a[j] && stack->base_a[j] != ' ')
			{
				free(stack->base_a);
				error();
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

// /*-------------------------------------------------------------*/
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
				error();
		}
		while (str[i] && str)
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
				i++;
			else
				error();
		}
	}
}
/*✅-----------------------------------------------------------*/

void	check_negative_sign(char *str)
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
				error();
		}
		i++;
	}
}

/*✅-----------------------------------------------------------*/
void	check_empty(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		error();
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		else
			break ;
	}
	if (i == ft_strlen(arg))
		error();
}

/*============================================================*/