/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:30:49 by chguerre          #+#    #+#             */
/*   Updated: 2026/04/27 17:28:24 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include "../lib/libft/includes/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				contain;
}	t_node;

typedef struct s_master
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	int		qty_in_a;
	int		qty_in_b;
}	t_master;

int		parsing_num(int argc, char *argv[], t_master *master_s);

long	ft_strtol(char *str, int *error);
void	cleaner(void *value);

#endif // !PUSH_SWAP_H
