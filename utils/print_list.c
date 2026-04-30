/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:55:55 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 10:56:28 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *nodo_head)
{
	t_node	*nodo_actual;

	nodo_actual = nodo_head;
	while (nodo_actual != NULL)
	{
		ft_printf("Num: %d.\n", nodo_actual->contain);
		nodo_actual = nodo_actual->next;
	}
}
