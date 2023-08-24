/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 20:18:00 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/01 20:18:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_show(int a, int b)
{
	char	diz;
	char	uni;
	char	diz2;
	char	uni2;

	diz = a / 10 + '0';
	uni = a % 10 + '0';
	diz2 = b / 10 + '0';
	uni2 = b % 10 + '0';
	ft_putchar(diz);
	ft_putchar(uni);
	ft_putchar(' ');
	ft_putchar(diz2);
	ft_putchar(uni2);
	if (a != 98 || b != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_show(a, b);
			b++;
		}
		a++;
	}
}
