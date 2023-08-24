/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:29:13 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/23 08:33:37 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	croiss;
	int	decroiss;

	i = 1;
	croiss = 1;
	decroiss = 1;
	if (length <= 1)
		return (1);
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			decroiss = 0;
		i++;
	}
	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			croiss = 0;
		i++;
	}
	if (croiss || decroiss)
		return (1);
	return (0);
}
