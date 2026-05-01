/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:07:33 by chguerr           #+#    #+#             */
/*   Updated: 2026/05/01 11:05:40 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_node *nodo_head)
{
	t_node	*nodo_actual;

	nodo_actual = nodo_head;
	while (nodo_actual != NULL)
	{
		ft_printf("Index:%d, Num: %d.\n", nodo_actual->index,
			nodo_actual->contain);
		nodo_actual = nodo_actual->next;
	}
}
