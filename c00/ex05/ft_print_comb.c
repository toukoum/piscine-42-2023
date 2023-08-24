/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:20:45 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/01 19:23:40 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int num, int num2, int num3)
{
	char	digit;
	char	digit2;
	char	digit3;

	digit = num + '0';
	digit2 = num2 + '0';
	digit3 = num3 + '0';
	ft_putchar(digit);
	ft_putchar(digit2);
	ft_putchar(digit3);
}

void	ft_print_comb(void)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				ft_print_number(i, j, k);
				if (i < 7 || j < 8 || k < 9)
					write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}
