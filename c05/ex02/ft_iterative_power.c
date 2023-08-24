/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:45:43 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/10 14:04:51 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	if (power < 0)
	{
		return (0);
	}
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}
