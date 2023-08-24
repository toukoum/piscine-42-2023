/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:57:43 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/13 19:16:48 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_rush_main(int tab_config[4][4]);
int		ft_check_board_duplicate(int **tab_solution, int num, int i, int j);
int		ft_check_col(int tab_config[4][4], int **tab_solution, int i, int j);
int		ft_check_line(int tab_config[4][4], int **tab_solution, int j, int i);
void	ft_display_solution(int **tab_solution, int *sol_found);
int		ft_check_param(int i, int j, int argc, char **argv);

int	*ft_next_ij(int i, int j)
{
	int	next_i;
	int	next_j;
	int	*tab_next;

	tab_next = malloc(sizeof(int) * 2);
	if (!tab_next)
	{
		free(tab_next);
		return (0);
	}
	next_i = i + 1;
	next_j = j;
	if (next_i == 4)
	{
		next_i = 0;
		next_j++;
	}
	tab_next[0] = next_i;
	tab_next[1] = next_j;
	return (tab_next);
}

void	ft_fill_board(int tab_config[4][4], int **tab_solution, int rc[2],
		int *sol_found)
{
	int	num;
	int	next_rc[2];
	int	*next_indices;

	ft_display_solution(tab_solution, sol_found);
	if (*sol_found == 1)
		return ;
	next_indices = ft_next_ij(rc[0], rc[1]);
	next_rc[0] = next_indices[0];
	next_rc[1] = next_indices[1];
	free(next_indices);
	num = 0;
	while (++num < 5)
	{
		if (ft_check_board_duplicate(tab_solution, num, rc[0], rc[1]))
		{
			tab_solution[rc[1]][rc[0]] = num;
			if ((rc[0] < 3 || ft_check_line(tab_config, tab_solution, rc[1], 0))
				&& (rc[1] < 3
					|| ft_check_col(tab_config, tab_solution, rc[0], 0)))
				ft_fill_board(tab_config, tab_solution, next_rc, sol_found);
			tab_solution[rc[1]][rc[0]] = 0;
		}
	}
}

void	ft_init_tab_sol(int **tab_solution, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < n)
	{
		tab_solution[j] = malloc(n * sizeof(int));
		if (tab_solution[j] == NULL)
		{
			while (j > 0)
				free(tab_solution[--j]);
			return ;
		}
		while (i < n)
		{
			tab_solution[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_rush_main(int tab_config[4][4])
{
	int	n;
	int	**tab_solution;
	int	rc[2];
	int	sol_found;
	int	i;

	sol_found = 0;
	rc[0] = 0;
	rc[1] = 0;
	n = 4;
	tab_solution = malloc(n * sizeof(int *));
	if (tab_solution == NULL)
		return ;
	ft_init_tab_sol(tab_solution, n);
	ft_fill_board(tab_config, tab_solution, rc, &sol_found);
	if (!sol_found)
		write(1, "Error\n", 6);
	i = -1;
	while (++i < n)
		free(tab_solution[i]);
	free(tab_solution);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_check_param(i, j, argc, argv))
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
