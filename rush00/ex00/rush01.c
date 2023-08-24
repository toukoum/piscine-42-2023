/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:23:16 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/06 09:46:47 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_display_01(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == x && j == y && x != 1 && y != 1))
	{
		ft_putchar('/');
	}
	else if ((i == x && j == 1) || (j == y && i == 1))
	{
		ft_putchar('\\');
	}
	else if ((j > 1 && j < y) && (i > 1 && i < x))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('*');
	}
}

void	rush01(int x, int y)
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
				ft_display_01(i, j, x, y);
				i++;
			}
			i = 1;
			ft_putchar('\n');
			j++;
		}
	}
}
