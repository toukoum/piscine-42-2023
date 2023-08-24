/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:03:00 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/06 09:50:09 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_display_00(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (j == y && i == 1)
		|| (i == x && j == 1) || (i == x && j == y))
	{
		ft_putchar('o');
	}
	else if ((i > 1 && i < x) && (j == 1 || j == y))
	{
		ft_putchar('-');
	}
	else if ((j > 1 && j < y) && (i > 1 && i < x))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('|');
	}
}

void	rush00(int x, int y)
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
				ft_display_00(i, j, x, y);
				i++;
			}
			i = 1;
			ft_putchar('\n');
			j++;
		}
	}
}
