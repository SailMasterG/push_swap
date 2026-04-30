/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:01:56 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 21:02:04 by chguerr          ###   ########.ch       */
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
	int				index;
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
void	print_list(t_node *nodo_head);
//**Operations
void	sa(t_manager *stack);
void	sb(t_manager *stack);
void	ss(t_manager *stack);

void	pb(t_manager *stack);
void	pa(t_manager *stack);

void	ra(t_manager *stack);
void	rb(t_manager *stack);
void	rra(t_manager *stack);
void	rrb(t_manager *stack);
void	rrr(t_manager *stack);

int		sort_three_numbers(t_manager *stack);
void	radix_sort(t_manager *stack);
void	parsing_index(t_manager *stack);
#endif // PUSH_SWAP_H
