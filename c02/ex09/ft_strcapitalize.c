/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:56:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/03 18:56:56 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		is_start_of_word;

	i = 0;
	is_start_of_word = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (is_start_of_word && str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
			}
			is_start_of_word = 0;
		}
		else
		{
			is_start_of_word = 1;
		}
		i++;
	}
	return (str);
}
