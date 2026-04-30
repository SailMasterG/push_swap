/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 23:40:59 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 23:59:50 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_manager *stack)
{
	t_node	*temp;

	temp = stack->head_a;
	while (temp->next != NULL)
	{
		if (temp->contain > temp->next->contain)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	sort_elements(t_manager *stack)
{
	if (stack->qty_in_a == 2)
	{
		if (stack->head_a->contain > stack->tail_a->contain)
			sa(stack);
	}
	else if (stack->qty_in_a >= 4)
	{
		radix_sort(stack);
	}
	else
		sort_three_numbers(stack);
}

int	main(int argc, char *argv[])
{
	t_manager	stack;

	if (argc < 2)
		return (1);
	ft_bzero(&stack, sizeof(t_manager));
	if (parsing_args(argc, argv, &stack) == 0)
	{
		free_all_stacks(&stack);
		return (1);
	}
	if (!is_sorted(&stack))
	{
		sort_elements(&stack);
	}
	free_all_stacks(&stack);
	return (0);
}
