#include "push_swap.h"

// struct		stack
// {
// 	int				first_num;
// 	struct	stack	*next_num;
// };

/*-------------------------------------------------------------*/
/**
 ** create a new stack
 ** if stack_a is NULL, it is an empty list
 ** otherwise, find the last stack and add the newstack
 ** last stack's next_num address will be NULL.
 ** add the newstack at the end of the linked list
 */
// void addLast(struct stack **stack_a, int num)
// {
// 	struct stack *newstack = malloc(sizeof(struct stack));

// 	newstack -> first_num = num;
// 	newstack->next_num = NULL;

// 	if(*stack_a == NULL)
// 		 *stack_a = newstack;
// 	else
// 	{
// 		struct stack *laststack;
// 		laststack = *stack_a;
// 		while(laststack->next_num != NULL)
// 			laststack = laststack->next_num;
// 		laststack->next_num = newstack;
// 	}
// }
/*-------------------------------------------------------------*/
// void find_dups(struct stack *stack_a)
// {
// 	while (stack_a->next_num != NULL)
// 	{
// 		struct stack *ptr = stack_a->next_num;
// 		while (ptr != NULL)
// 		{
// 			if (stack_a->first_num == ptr->first_num)
// 				error();
// 			ptr = ptr->next_num;
// 		}
// 		stack_a = stack_a->next_num;
// 	}
// }
/*-------------------------------------------------------------*/
// void printList(struct stack *stack_a)
// {
// 	struct stack *temp = stack_a;

// 	while(temp != NULL)
// 	{
// 		printf("%d\n", temp->first_num);
// 		temp = temp->next_num;
// 	}
// 	printf("NULL\n");
// }
/*-------------------------------------------------------------*/
// int main(int argc, char **argv)
// {
// 	int		i;
// 	int		j;
// 	int		s;
// 	int		num;
// 	char	**split;

// 	i = 1;
// 	j = 0;
// 	s = 0;
// 	if (argc >= 2)
// 	{
// 		struct stack *stack_a = NULL;
// 		while (argv[i])
// 		{
// 			while (argv[i][j])
// 			{
// 				if (argv[i][j] == ' ')
// 				{
// 					split = ft_split(argv[i], ' ');
// 					while (split[s])
// 					{
// 						num = ft_atoi(split[s]);
// 						addLast(&stack_a,num);
// 						s++;
// 					}
// 					free(split);
// 					split = NULL;
// 					i++;
// 					j = 0;
// 					break ;
// 				}
// 				else
// 					j++;
// 			}
// 			j = 0;
// 			if (argv[i])
// 			{
// 				check_length(argv[i]);
// 				check_digit_multi(argv[i]);
// 				if(ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
// 					error();
// 				num = ft_atoi(argv[i]);
// 				addLast(&stack_a,num);
// 				i++;
// 			}
// 		}
// 		find_dups(stack_a);
// 	 	printList(stack_a);
// 	}
// 	else
// 		error();
// 	return (0);
// }
/*-------------------------------------------------------------*/
