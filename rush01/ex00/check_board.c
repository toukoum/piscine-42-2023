/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:44:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/13 19:08:56 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_board_duplicate(int **tab_solution, int num, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (tab_solution[j][k] == num)
		{
			return (0);
		}
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (tab_solution[k][i] == num)
		{
			return (0);
		}
		k++;
	}
	return (1);
}

void	initialize_variables(int *count_top, int *count_bottom, int *max_top,
		int *max_bottom)
{
	*count_top = 0;
	*count_bottom = 0;
	*max_top = 0;
	*max_bottom = 0;
}

int	ft_check_col(int tab_config[4][4], int **tab_solution, int i, int j)
{
	int	count_top;
	int	count_bottom;
	int	max_top;
	int	max_bottom;

	initialize_variables(&count_top, &count_bottom, &max_top, &max_bottom);
	while (j < 4)
	{
		if (tab_solution[j][i] > max_top)
		{
			max_top = tab_solution[j][i];
			count_top++;
		}
		if (tab_solution[3 - j][i] > max_bottom)
		{
			max_bottom = tab_solution[3 - j][i];
			count_bottom++;
		}
		j++;
	}
	if (tab_config[0][i] == count_top && tab_config[1][i] == count_bottom)
		return (1);
	else
		return (0);
}

void	ft_init_variable1(int *count_start, int *count_end, int *max_start,
		int *max_end)
{
	*count_start = 0;
	*count_end = 0;
	*max_start = 0;
	*max_end = 0;
}

int	ft_check_line(int tab_config[4][4], int **tab_solution, int j, int i)
{
	int	count_start;
	int	count_end;
	int	max_start;
	int	max_end;

	ft_init_variable1(&count_start, &count_end, &max_start, &max_end);
	while (i < 4)
	{
		if (tab_solution[j][i] > max_start)
		{
			max_start = tab_solution[j][i];
			count_start++;
		}
		if (tab_solution[j][3 - i] > max_end)
		{
			max_end = tab_solution[j][3 - i];
			count_end++;
		}
		i++;
	}
	if (tab_config[2][j] == count_start && tab_config[3][j] == count_end)
		return (1);
	else
		return (0);
}
