/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:10:38 by chguerre          #+#    #+#             */
/*   Updated: 2026/04/27 21:54:44 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_duplicate(int num, t_master *master_s)
{
	t_node *current_node;
	current_node = master_s->head_a;
	while (current_node)
	{
		if(current_node->contain == num)
			return(1);
		current_node = current_node->next;
	}
	return (0);
}

void add_to_tail(t_node *node, t_master *master_s)
{
	if(!node)
		return;
	if(master_s->tail_a == NULL)
	{
		master_s->head_a = node;
		master_s->tail_a = node;
		master_s->qty_in_a = 1;
	}
	else
	{
		node->prev = master_s->tail_a;
		node->next = NULL;
		master_s->tail_a->next = node;
		master_s->tail_a = node;
		master_s->qty_in_a += 1;
	}

}

t_node *create_node(int num)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if(new_node == NULL)
		return(NULL);
	new_node->contain = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return(new_node);
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
		return(*error = 1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr_long = nbr_long * 10 + (str[i] - '0');
		i++;
	}
	nbr_long *= sign;
	if (str[i] != '\0' || (nbr_long < INT_MIN || nbr_long > INT_MAX))
		return (*error = 1);
	return (nbr_long);
}
