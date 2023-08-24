/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 08:15:45 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/10 08:23:26 by rgiraud          ###   ########.fr       */
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

int	main(int argc, char const *argv[])
{
	int	i;

	if (argc == 1)
	{
		return (0);
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
