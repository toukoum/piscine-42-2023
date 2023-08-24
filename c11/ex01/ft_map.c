/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:49:46 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/20 08:05:34 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result_tab;
	int	i;

	result_tab = malloc(length * sizeof(int));
	if (!result_tab)
		return (0);
	i = 0;
	while (i < length)
	{
		result_tab[i] = f(tab[i]);
		i++;
	}
	return (result_tab);
}
