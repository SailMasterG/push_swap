/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:23:44 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 11:23:41 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_logic(t_node **head, t_node **tail)
{
	t_node	*last;
	t_node	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return (0);
	last = *tail;
	new_tail = last->prev;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
	last->prev = NULL;
	*tail = new_tail;
	(*tail)->next = NULL;
	return (1);
}

void	rra(t_manager *stack)
{
	if (reverse_rotate_logic(&stack->head_a, &stack->tail_a))
		write(1, "rra\n", 4);
}

void	rrb(t_manager *stack)
{
	if (reverse_rotate_logic(&stack->head_b, &stack->tail_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_manager *stack)
{
	if (stack->qty_in_a >= 2 && stack->qty_in_b >= 2)
	{
		reverse_rotate_logic(&stack->head_a, &stack->tail_a);
		reverse_rotate_logic(&stack->head_b, &stack->tail_b);
		write(1, "rrr\n", 4);
	}
}
