/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:09:05 by mjean-lo          #+#    #+#             */
/*   Updated: 2023/08/05 20:10:48 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_display_03(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (j == y && i == 1))
	{
		ft_putchar('A');
	}
	else if ((i == x && j == 1) || (j == y && i == x))
	{
		ft_putchar('C');
	}
	else if ((j > 1 && j < y) && (i > 1 && i < x))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('B');
	}
}

void	rush03(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	if (x > 0 && y > 0)
	{
		while (j <= y)
		{
			while (i <= x)
			{
				ft_display_03(i, j, x, y);
				i++;
			}
			i = 1;
			ft_putchar('\n');
			j++;
		}
	}
}
