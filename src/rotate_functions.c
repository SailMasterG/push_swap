/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:15:17 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/29 16:21:15 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_logic(t_node **head, t_node **tail)
{
	t_node	*first;

	first = *head;
	if (*head == NULL || (*head)->next == NULL)
		return (0);
	*head = first->next;
	(*head)->prev = NULL;
	(*tail)->next = first;
	first->prev = *tail;
	(*tail) = first;
	(*tail)->next = NULL;
	return (1);
}

void	ra(t_manager *stack)
{
	if (rotate_logic(&stack->head_a, &stack->tail_a))
	{
		write(1, "ra\n", 3);
	}
}

void	rb(t_manager *stack)
{
	if (rotate_logic(&stack->head_b, &stack->tail_b))
	{
		write(1, "rb\n", 3);
	}
}

void	rr(t_manager *stack)
{
	if (stack->qty_in_a >= 2 && stack->qty_in_b >= 2)
	{
		rotate_logic(&stack->head_a, &stack->tail_a);
		rotate_logic(&stack->head_b, &stack->tail_b);
		write(1, "rr\n", 3);
	}
}
