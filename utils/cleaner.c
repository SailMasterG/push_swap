/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:13:04 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/28 13:13:43 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node_list(t_node *head)
{
	t_node	*current;
	t_node	*temp_next;

	current = head;
	temp_next = NULL;
	while (current != NULL)
	{
		temp_next = current->next;
		free(current);
		current = temp_next;
	}
}

void	free_all_stacks(t_manager *stack)
{
	ft_free_node_list(stack->head_a);
	ft_free_node_list(stack->head_b);
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->tail_a = NULL;
	stack->tail_b = NULL;
	stack->qty_in_a = 0;
	stack->qty_in_b = 0;
}

int	free_split(char **split_v)
{
	int	i;

	i = 0;
	if (split_v == NULL)
		return (0);
	while (split_v[i] != NULL)
	{
		free(split_v[i]);
		i++;
	}
	free(split_v);
	split_v = NULL;
	return (1);
}
