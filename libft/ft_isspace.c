#include "libft.h"

int	ft_isspace(int n)
{
	if (n == ' ' || n == '\n' || n == '\t'
		|| n == '\v' || n == '\f' || n == '\r')
	{
		return (1);
	}
	return (0);
}
