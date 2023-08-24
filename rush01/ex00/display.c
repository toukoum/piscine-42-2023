/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:45:40 by pgrellie          #+#    #+#             */
/*   Updated: 2023/08/13 19:01:58 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int x)
{
	write (1, &x, 1);
}

void	ft_display_solution(int **tab_solution, int *sol_found)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (tab_solution[3][3] != 0)
	{
		while (y < 4)
		{
			while (x < 4)
			{
				ft_putchar(tab_solution[y][x] + '0');
				if (x < 3)
					ft_putchar(' ');
				x++;
			}
			ft_putchar('\n');
			x = 0;
			y++;
		}
		*sol_found = 1;
	}
}
