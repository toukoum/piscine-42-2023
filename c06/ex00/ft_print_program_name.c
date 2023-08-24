/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:55:44 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/14 11:29:11 by rgiraud          ###   ########.fr       */
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
	(void) argc;
	ft_put_str(argv[0]);
	return (0);
}
