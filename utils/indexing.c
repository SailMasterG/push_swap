/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:53:46 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 16:53:46 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_generator(t_node *head, int num)
{
	t_node *temp;
	int index;

	index = 0;
	temp = head;
	while (temp != NULL)
	{
		if (num > temp->contain)
			index++;
		temp = temp->next;
	}
	return (index);    
}

void parsing_index(t_manager *stack)
{
	t_node *current;

	current = stack->head_a;
	while (current != NULL)
	{
		current->index = index_generator(stack->head_a, current->contain);
		current = current->next;
	}

}