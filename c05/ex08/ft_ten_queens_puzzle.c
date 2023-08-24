/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:42:14 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/10 16:14:02 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int board[10][10]);

void	ft_board_init(int board[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	ft_check_pos(int board[10][10], int queen_col, int queen_row)
{
	int	i;
	int	j;

	i = queen_col - 1;
	j = queen_row - 1;
	while (i >= 0)
	{
		if (board[i][queen_row])
			return (0);
		if (board[i][queen_row - (queen_col - i)]
		&& (queen_row - (queen_col - i)) >= 0)
			return (0);
		j = queen_row;
		if (board[i][queen_row + (queen_col - i)]
		&& (queen_row + (queen_col - i)) <= 9)
			return (0);
		j++;
		i--;
	}	
	return (1);
}

void	ft_find_solution(int board[10][10], int queen_col, int *sol_count)
{
	int	j;

	if (queen_col == 10)
	{
		ft_print_solution(board);
		(*sol_count)++;
		return ;
	}
	j = 0;
	while (j < 10)
	{
		board[queen_col][j] = ft_check_pos(board, queen_col, j);
		if (board[queen_col][j])
			ft_find_solution(board, queen_col + 1, sol_count);
		board[queen_col][j] = 0;
		j++;
	}
	return ;
}

void	ft_print_solution(int board[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j])
			{
				j = j + '0';
				write(1, &j, 1);
				break ;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	ft_ten_queens_puzzle(void)
{
	int	solution_count;
	int	board[10][10];

	solution_count = 0;
	ft_board_init(board);
	ft_find_solution(board, 0, &solution_count);
	return (solution_count);
}
