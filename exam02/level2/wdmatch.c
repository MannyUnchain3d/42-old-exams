/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:06:53 by Manny             #+#    #+#             */
/*   Updated: 2023/03/08 15:06:55 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	char	*tmp;

	if (ac == 3)
	{
		tmp = av[1];
		while (*tmp && *av[2])
		{
			while (*tmp == *av[2] && (*tmp && *av[2]))
			{
				tmp++;
				av[2]++;
			}
			av[2]++;
		}
		if (!(*tmp))
			ft_putstr(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
