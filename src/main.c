/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:48:36 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 21:48:36 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack.qty_in_a >=4)
	{
		radix_sort(&stack);
	}
	else
		sort_three_numbers(&stack);
	free_all_stacks(&stack);
	return (0);
}
