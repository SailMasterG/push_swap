/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:34:42 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/28 19:00:52 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_top(t_node **head, t_node **tail, int qty)
{
	t_node	*first;
	t_node	*second;

	if (qty <= 1)
		return (0);
	first = *head;
	second = first->next;
	first->prev = second;
	if (qty > 2)
	{
		first->next = second->next;
		first->next->prev = first;
	}
	else
	{
		first->next = NULL;
		*tail = first;
	}
	second->next = first;
	second->prev = NULL;
	*head = second;
	return (1);
}

void	sa(t_manager *stack)
{
	if (swap_top(&stack->head_a, &stack->tail_a, stack->qty_in_a))
		write(1, "sa\n", 3);
}

void	sb(t_manager *stack)
{
	if (swap_top(&stack->head_b, &stack->tail_b, stack->qty_in_b))
		write(1, "sb\n", 3);
}

void	ss(t_manager *stack)
{
	if (stack->qty_in_a >= 2 && stack->qty_in_b >= 2)
	{
		swap_top(&stack->head_a, &stack->tail_a, stack->qty_in_a);
		swap_top(&stack->head_b, &stack->tail_b, stack->qty_in_b);
		write(1, "ss\n", 3);
	}
}
