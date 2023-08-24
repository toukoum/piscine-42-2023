/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:33:12 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/17 08:05:07 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_str_dup(char *str, int len)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(len * sizeof(char) + 1);
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_tab_result(t_stock_str *result_tab, int i)
{
	while (i >= 0)
	{
		free(result_tab[i].copy);
		i--;
	}
	free(result_tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result_tab;
	int			i;
	int			len_str;

	result_tab = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (result_tab == NULL)
	{
		return (NULL);
	}
	i = -1;
	while (++i < ac)
	{
		len_str = ft_str_len(av[i]);
		result_tab[i].size = len_str;
		result_tab[i].str = av[i];
		result_tab[i].copy = ft_str_dup(av[i], len_str);
		if (!result_tab[i].copy)
		{
			ft_free_tab_result(result_tab, i);
			return (NULL);
		}
	}
	result_tab[i].str = 0;
	result_tab[i].copy = 0;
	return (result_tab);
}
