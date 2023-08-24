/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:50:13 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/16 09:56:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlens(char **strs, int size)
{
	int	i;
	int	j;
	int	len_strs;

	len_strs = 0;
	j = 0;
	i = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			len_strs++;
			j++;
		}
		j = 0;
		i++;
	}
	return (len_strs);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_add_sep(char *result, char *sep, int *k)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		result[*k] = sep[i];
		(*k)++;
		i++;
	}
}

char	*ft_fill_result(char **strs, char *result, int size, char *sep)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			result[k] = strs[i][j];
			j++;
			k++;
		}
		if (i < size - 1)
			ft_add_sep(result, sep, &k);
		j = 0;
		i++;
	}
	result[k] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_strs;
	char	*empty_string;
	char	*result;
	int		len_sep;

	if (size == 0)
	{
		empty_string = malloc(1);
		empty_string[0] = '\0';
		return (empty_string);
	}
	len_sep = ft_strlen(sep);
	len_strs = ft_strlens(strs, size) + (len_sep * (size - 1) + 1);
	result = malloc(len_strs * sizeof(char));
	if (!result)
		return (NULL);
	ft_fill_result(strs, result, size, sep);
	return (result);
}
