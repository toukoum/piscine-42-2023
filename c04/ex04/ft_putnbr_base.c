/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:42:06 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/09 12:41:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_display(int i, char *result)
{
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	result[100];
	int		i;
	long	n;

	n = nbr;
	i = 0;
	if (!ft_check_base(base))
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
	{
		result[i++] = base[0];
	}
	while (n)
	{
		result[i++] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	i -= 1;
	ft_display(i, result);
}
