/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:37:47 by Manny             #+#    #+#             */
/*   Updated: 2023/03/08 15:19:56 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
