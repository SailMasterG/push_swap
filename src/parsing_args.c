/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerr <chguerr@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:16:22 by chguerr           #+#    #+#             */
/*   Updated: 2026/04/30 11:17:52 by chguerr          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Esta funcion sirve como auxiliar a parsing arg para
 *  recorrer los tokens (string), a la cual se le ha aplicado split.
 * @param tokens 
 * @param stack 
 * @return int 
 */
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
 * @brief Esta funcion tiene la logica para intentar convertir 
 * la cadena en un numero entero(long)
 * usa intername ft_strtol para convertir el long entero y devolver el error 
 * si esta fuera de los limites de INT_MAX e INT MIN, 
 * Si hay un error devuelve 0, y la funcion que lo llama gestiona el free(), 
 * a su vez la funcion iterate token, devuelve 0 para 
 * liberar el resto de la pila.
 * *#ft_strol Toma en cuenta los casos bordes, un solo signo, cadena vacia.
 * *#Verifica si hay un Duplicado del numero dentro de
 *  la pila , si encuentra un duplicado retorna 0.
 * *#Crea el Nodo y luego lo agrega al final
 * @param str_num 
 * @param stack 
 * @return int 
 */
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

/**
 * @brief Esta funcion se encarga de hacer los split del
 *  valor despues del 2 argumento en adelante,
 * estos luegos se convierten en tokens, maneja correctamente
 *  si hay un error en la creacion del split, 
 * en cada iteracion el bucle while libera el 
 * split para evitar fugas. 
 * *#Si esta funcion retorna (0) libera todo el stack en el main.
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
