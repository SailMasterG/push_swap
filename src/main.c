/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:22:40 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/28 13:22:40 by chguerr          ###   ########.ch       */
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

int	main(int argc, char *argv[])
{
	t_manager	stack;

	if (argc < 2)
		return (1);
	ft_bzero(&stack, sizeof(t_manager));
	if (parsing_args(argc, argv, &stack) == 0)
	{
		free_all_stacks(&stack);
		return (1);
	}
	print_list(stack.head_a);
	free_all_stacks(&stack);
	return (0);
}

int	process_string(char *str_num, t_manager *stack)
{
	long	num;
	int		error;
	t_node	*new_node;

	error = 0;
	num = ft_strtol(str_num, &error);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_duplicate(num, stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	new_node = create_node(num);
	if (!new_node)
		return (0);
	add_to_tail(new_node, stack);
	return (1);
}

static int	iterate_tokens(char **tokens, t_manager *stack)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!process_string(tokens[i], stack))
		{
			free_split(tokens);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * @brief Esta funcion se encarga de validar los argumentos,
 * y de crear los nodos de la pila (a);
 *
 * @param argc
 * @param argv
 * @param stacktack
 * @return int
 */
int	parsing_args(int argc, char *argv[], t_manager *stack)
{
	int		i;
	char	**tokens;

	i = 1;
	tokens = NULL;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			write(2, "Error\n", 6);
			return (0);
		}
		if (!iterate_tokens(tokens, stack))
			return (0);
		i++;
		free_split(tokens);
	}
	return (1);
}
