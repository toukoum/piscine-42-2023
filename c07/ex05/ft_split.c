/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 08:42:49 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/19 08:50:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	ft_count_word(char *str, char *charset, int count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			count++;
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
	}
	return (count);
}

void	ft_add_word_to_result(char *start, char **result, int *count, char *str)
{
	int		len_word;
	int		index;
	char	*word;

	index = 0;
	len_word = str - start;
	if (len_word == 0)
	{
		(*count)--;
		return ;
	}
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return ;
	result[*count] = word;
	while (index < len_word)
	{
		result[*count][index] = *start;
		start++;
		index++;
	}
	result[*count][index] = '\0';
}

void	ft_fill_result(char **result, char *str, char *charset, int count)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			j = i;
			while (str[j] && !is_separator(str[j], charset))
				j++;
			ft_add_word_to_result(&str[i], result, &count, &str[j]);
			count++;
			i = j;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		nb_word;
	int		count;
	int		i;
	char	**result;

	count = 0;
	i = 0;
	nb_word = ft_count_word(str, charset, count);
	result = malloc((nb_word + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_fill_result(result, str, charset, count);
	result[nb_word] = 0;
	return (result);
}
