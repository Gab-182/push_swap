#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*------------------------------------------------------*/
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

/*------------------------------------------------------*/
void	ft_putchar(int c)
{
	write (1, &c, 1);
}

/*------------------------------------------------------*/
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

/*------------------------------------------------------*/