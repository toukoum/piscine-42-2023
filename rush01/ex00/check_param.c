/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:55:21 by htassain          #+#    #+#             */
/*   Updated: 2023/08/13 19:11:27 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rush_main(int tab_config[4][4]);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4' && (i % 2 == 0))
		{
			i++;
		}
		else if (argv[1][i] == ' ' && (i % 2 == 1))
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}

int	ft_check_param(int i, int j, int argc, char **argv)
{
	int	k;
	int	tab_config[4][4];

	if (argc == 2 && ft_strlen(argv[1]) == 31 && ft_check_argv(argv))
	{
		k = 0;
		while (argv[1][i] != '\0')
		{
			if (k > 3)
			{
				j++;
				k = 0;
			}
			if (argv[1][i] >= '1' && argv[1][i] <= '4')
			{
				tab_config[j][k] = argv[1][i] - 48;
				k++;
			}
			i++;
		}
		ft_rush_main(tab_config);
		return (1);
	}
	else
		return (0);
}
