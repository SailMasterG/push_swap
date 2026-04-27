/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chguerre <chguerre@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:10:38 by chguerre          #+#    #+#             */
/*   Updated: 2026/04/27 17:39:10 by chguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_strtol(char *str, int *error)
{
	long	nbr_long;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	nbr_long = 0;
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
