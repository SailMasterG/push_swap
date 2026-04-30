/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 00:00:26 by chguerr           #+#    #+#             */
/*   Updated: 2026/05/01 00:00:34 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sel_mov(t_manager *stack, int head, int next, int tail)
{
	if (head < next && head < tail && next < tail)
		return ;
	else if (head < next && head < tail && next > tail)
	{
		rra(stack);
		sa(stack);
	}
	else if (head > next && head < tail)
		sa(stack);
	else if (head < next && head > tail)
		rra(stack);
	else if (head > next && head > tail && next < tail)
		ra(stack);
	else if (head > next && head > tail && next > tail)
	{
		sa(stack);
		rra(stack);
	}
}

int	sort_three_numbers(t_manager *stack)
{
	int	head;
	int	next;
	int	tail;

	if (stack->qty_in_a != 3)
		return (0);
	head = stack->head_a->contain;
	next = stack->head_a->next->contain;
	tail = stack->tail_a->contain;
	sel_mov(stack, head, next, tail);
	return (1);
}
