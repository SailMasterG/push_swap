/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:16:26 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/28 13:19:07 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int num, t_manager *stack)
{
	t_node	*current_node;

	current_node = stack->head_a;
	while (current_node)
	{
		if (current_node->contain == num)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

void	add_to_tail(t_node *node, t_manager *stack)
{
	if (!node)
		return ;
	if (stack->tail_a == NULL)
	{
		stack->head_a = node;
		stack->tail_a = node;
		stack->qty_in_a = 1;
	}
	else
	{
		node->prev = stack->tail_a;
		node->next = NULL;
		stack->tail_a->next = node;
		stack->tail_a = node;
		stack->qty_in_a += 1;
	}
}

t_node	*create_node(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->contain = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	parsing_long(char *str, int *i, long *result)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
	}
}

long	ft_strtol(char *str, int *error)
{
	long	nbr_long;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	nbr_long = 0;
	if (str[i] == '\0')
		return (*error = 1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (*error = 1);
	parsing_long(str, &i, &nbr_long);
	nbr_long *= sign;
	if (str[i] != '\0' || (nbr_long < INT_MIN || nbr_long > INT_MAX))
		return (*error = 1);
	return (nbr_long);
}
