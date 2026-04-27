/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:32:03 by chguerre          #+#    #+#             */
/*   Updated: 2026/04/27 17:37:58 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Esta funcion se encarga de validar los argumentos,
 * y de crear los nodos de la pila (a);
 *
 * @param argc
 * @param argv
 * @param master_stack
 * @return int
 */
int	parsing_num(int argc, char *argv[], t_master *master_s);

int	main(int argc, char *argv[])
{
	t_master	master_s;

	if (argc < 2)
		return (1);
	ft_bzero(&master_s, sizeof(t_master));
	if (parsing_num(argc, argv, &master_s) == 0)
		return (1);
	return (0);
}

int	free_split(char **split_v)
{
	int	i;

	i = 0;
	if (split_v == NULL)
		return (0);
	while (split_v[i] != NULL)
	{
		free(split_v[i]);
		i++;
	}
	free(split_v);
	split_v = NULL;
	return (1);
}

int	process_string(char *str_num, t_master *master_s)
{
	long	num;
	int		error;

	error = 0;
	(void)master_s;
	num = ft_strtol(str_num, error);
	/*
	1-Procesar cadena con ft_strol() necesito crearla
	2-verificar si tiene duplicados dentro de la fila
	3-Creamos nodo + añadirlo a Tail A
	retornar 0 / 1.
	*/
	return (0);

}

int	parsing_num(int argc, char *argv[], t_master *master_s)
{
	int		j;
	int		i;
	char	**str_numero;

	i = 1;
	str_numero = NULL;
	while (i < argc)
	{
		str_numero = ft_split(argv[i], ' ');
		if (!str_numero || !str_numero[0])
		{
			free_split(str_numero);
			return (0);
		}
		j = 0;
		while (str_numero[j])
		{
			if (!process_string(str_numero[j], master_s))
			{
				free_split(str_numero);
				//Liberar Pila (Necesito crear Funcion)
				return (0);
			}
			j++;
		}
		i++;
		free_split(str_numero);
	}
	return (1);
}
