#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
/*============================================================*/
// int	*if_space(char *argv)
// {
// 	int	i;
// 	int *num;

// 	i = 0;
// 	if (!argv)
// 		return (0);
// 	num = (int *)malloc(sizeof(int) * ft_strlen(argv) + 1);
// 	while (argv[i])
// 	{
// 		num[i] = ft_atoi(argv[i]);
// 		i++;
// 	}
// 	return (num);
// }

/*============================================================*/
int main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*num;

	j = 0;
	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				if (argv[i][j] == ' ')
				{
					printf("argv[%d] = %d\n", i, atoi(argv[i]));
					break;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
/*============================================================*/

int	main()
{
	printf("%d\n", atoi("12 23 43"));
}