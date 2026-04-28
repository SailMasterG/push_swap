/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:44:29 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/28 18:44:29 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../lib/libft/includes/libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				contain;
}	t_node;

typedef struct s_manager
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	int		qty_in_a;
	int		qty_in_b;
}	t_manager;

int		parsing_args(int argc, char *argv[], t_manager *stack);
int		free_split(char **split_v);
int		process_string(char *str_num, t_manager *stack);
int		is_duplicate(int num, t_manager *stack);
t_node	*create_node(int num);
void	add_to_tail(t_node *node, t_manager *stack);

long	ft_strtol(char *str, int *error);
void	free_all_stacks(t_manager *stack);
void	ft_free_node_list(t_node *head);

//**Operations
void	sa(t_manager *stack);
void	sb(t_manager *stack);
void	ss(t_manager *stack);
#endif // PUSH_SWAP_H
