/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 08:20:58 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/10 08:27:18 by rgiraud          ###   ########.fr       */
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
	while (argc > 1)
	{
		ft_put_str(argv[argc - 1]);
		ft_putchar('\n');
		argc--;
	}
	return (0);
}
