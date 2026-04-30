/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:05:25 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 21:48:04 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_back_in_a(t_manager *stack)
{
	while (stack->qty_in_b > 0)
		pa(stack);
}

void	radix_sort(t_manager *stack)
{
	int	max_bits;
	int	max_index;
	int	bit;
	int	size;

	bit = 0;
	size = 0;
	max_index = stack->qty_in_a - 1;
	max_bits = 0;
	while ((1 << max_bits) <= max_index)
		max_bits++;
	while (bit <= max_bits)
	{
		size = stack->qty_in_a - 1;
		while (size >= 0)
		{
			if (((stack->head_a->index >> bit) & 1) == 0)
				pb(stack);
			else
				ra(stack);
			size--;
		}
		put_back_in_a(stack);
		bit++;
	}
}
