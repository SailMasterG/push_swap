/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:10:38 by chguerre          #+#    #+#             */
/*   Updated: 2026/04/27 21:08:57 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_to_tail(t_node *node, t_master *master_s)
{
	t_node *current_node;
	if(master_s->tail_a == NULL)
	{
		master_s->tail_a->prev= current_node->prev;
		master_s->tail_a->next = current_node->next;
		master_s->tail_a = current_node;
	}
	else

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
