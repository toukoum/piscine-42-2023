/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:51:36 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/02 11:52:00 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_check_last_comb(char *comb, char *last_comb, int n)
{
	int	j;
	int	is_last_comb;

	j = 0;
	is_last_comb = 1;
	while (j < 10 - n)
	{
		if (comb[j] != last_comb[j])
		{
			is_last_comb = 0;
			break ;
		}
		j++;
	}
	if (!is_last_comb)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn_recursive(int n, int prev, char *comb, char *last_comb)
{
	int	i;

	if (n == 0)
	{
		write(1, comb, 10 - n);
		ft_check_last_comb(comb, last_comb, n);
		return ;
	}
	i = prev + 1;
	while (i <= 10 - n)
	{
		comb[10 - n] = i + '0';
		ft_print_combn_recursive(n - 1, i, comb, last_comb);
		i++;
	}
}

void	last_combination(int n, char *last_comb)
{
	int	i;

	i = 0;
	while (i < n)
	{
		last_comb[9 - i] = '9' - i;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	comb[10];
	char	last_comb[10];
	int		i;

	i = 0;
	if (n < 1 || n > 9)
	{
		return ;
	}
	while (i < 10)
	{
		comb[i] = 0;
		last_comb[i] = 0;
		i++;
	}
	last_combination(n, last_comb);
	ft_print_combn_recursive(n, -1, comb, last_comb);
}
