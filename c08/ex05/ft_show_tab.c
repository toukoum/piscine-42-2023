/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:02 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/17 08:13:33 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_put_str(char *str)
{
	write(1, str, ft_str_len(str));
}

void	ft_put_nbr(int nbr)
{
	if (nbr == -2147483648)
		ft_put_str("-2147483648");
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	else if (nbr > 9)
		ft_put_nbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_put_str(par[i].str);
		write(1, "\n", 1);
		ft_put_nbr(par[i].size);
		write(1, "\n", 1);
		ft_put_str(par[i].copy);
		write(1, "\n", 1);
	}
}
