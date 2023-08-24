/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 08:27:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/10 09:34:15 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_put_str(char const *chaine)
{
	int	i;

	i = 0;
	while (chaine[i])
	{
		ft_putchar(chaine[i]);
		i++;
	}
}

int	ft_str_comp(char *chaine1, char *chaine2)
{
	int	i;

	i = 0;
	while (chaine1[i] && chaine2[i] && chaine1[i] == chaine2[i])
	{
		i++;
	}
	return (chaine1[i] - chaine2[i]);
}

void	ft_swap(char **chaine1, char **chaine2)
{
	char	*tempo;

	tempo = *chaine1;
	*chaine1 = *chaine2;
	*chaine2 = tempo;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (j < (argc - i))
		{
			if (ft_str_comp(argv[j], argv[j + 1]) > 0)
			{
				ft_swap(&argv[j], &argv[j + 1]);
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		ft_put_str(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
