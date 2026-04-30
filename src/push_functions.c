/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:15:09 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/29 09:15:09 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_one_element_source(t_node *source, t_node **head, t_node **tail)
{
	if (source->next != NULL)
	{
		*head = source->next;
		source->next->prev = NULL;
	}
	else
	{
		*head = NULL;
		*tail = NULL;
	}
}

void	pb(t_manager *stack)
{
	t_node	*source;
	t_node	*dest;
	int		qty_origen;

	source = stack->head_a;
	dest = stack->head_b;
	qty_origen = stack->qty_in_a;
	if (qty_origen == 0)
		return ;
	is_one_element_source(source, &stack->head_a, &stack->tail_a);
	stack->head_b = source;
	stack->qty_in_a -= 1;
	stack->qty_in_b += 1;
	if (dest != NULL)
		dest->prev = source;
	else
		stack->tail_b = source;
	source->next = dest;
	source->prev = NULL;
	write(1, "pb\n", 3);
}

void	pa(t_manager *stack)
{
	t_node	*source;
	t_node	*dest;
	int		qty_origen;

	source = stack->head_b;
	dest = stack->head_a;
	qty_origen = stack->qty_in_b;
	if (qty_origen == 0)
		return ;
	is_one_element_source(source, &stack->head_b, &stack->tail_b);
	stack->head_a = source;
	stack->qty_in_b -= 1;
	stack->qty_in_a += 1;
	if (dest != NULL)
		dest->prev = source;
	else
		stack->tail_a = source;
	source->next = dest;
	source->prev = NULL;
	write(1, "pa\n", 3);
}
