/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:32:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/16 09:34:58 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *chaine)
{
	int	i;

	i = 0;
	while (chaine[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
