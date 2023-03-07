/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:30:02 by mhaan         #+#    #+#                 */
/*   Updated: 2023/03/07 15:54:59 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	check_error(argc, argv);
	stack_a = parse_arguments(argc, argv);
	if (argc <= 6)
		ps_short_sort(&stack_a);
	else
		ps_radix_sort(&stack_a);
	ps_stackclear(&stack_a);
	return (0);
}
