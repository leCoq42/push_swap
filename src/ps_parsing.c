/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_parsing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 13:34:18 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/07 15:46:10 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	update_index(t_stack **stack);

t_stack	*parse_arguments(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*node;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		node = ps_stacknew(num);
		if (!node)
			exit(EXIT_FAILURE);
		ps_stackadd_back(&stack, node);
		i++;
	}
	update_index(&stack);
	return (stack);
}

static void	update_index(t_stack **stack)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (!(*stack)->next)
		return ;
	ptr1 = (*stack);
	while (ptr1->next)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ptr1->num > ptr2->num)
				ptr1->idx++;
			else
				ptr2->idx++;
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}
