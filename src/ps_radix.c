/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_radix.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 13:52:20 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/01 17:33:42 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	is_revsorted(t_stack *stack);
static void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, unsigned int i);

void	ps_radix_sort(t_stack **stack_a)
{
	t_stack			*stack_b;
	unsigned int	stacklen;
	unsigned int	i;
	unsigned int	j;

	stack_b = NULL;
	i = 0;
	while (stack_b || !is_sorted(*stack_a))
	{
		j = 0;
		stacklen = ps_stacklen(*stack_a);
		while (j < stacklen && !is_sorted(*stack_a))
		{
			if (((*stack_a)->idx >> i) & 1)
				op_switch(stack_a, &stack_b, "ra", 1);
			else
				op_switch(stack_a, &stack_b, "pb", 1);
			j++;
		}
		i++;
		sort_stack_b(stack_a, &stack_b, i);
	}
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->idx > stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, unsigned int i)
{
	unsigned int	j;
	unsigned int	stacklen;

	j = 0;
	stacklen = ps_stacklen(*stack_b);
	while (stack_b && j < stacklen)
	{
		if ((*stack_b)->idx >> i & 1 || is_revsorted(*stack_b))
			op_switch(stack_a, stack_b, "pa", 1);
		else
			op_switch(stack_a, stack_b, "rb", 1);
		j++;
	}
}

static int	is_revsorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->idx < stack->next->idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}
