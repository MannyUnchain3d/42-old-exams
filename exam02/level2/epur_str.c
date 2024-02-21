/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:00:06 by Manny             #+#    #+#             */
/*   Updated: 2023/03/18 18:16:01 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	space;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while (av[1][i])
		{
			if (av[1][i] == 32 || av[1][i] == 9)
				space = 1;
			else if (!(av[1][i] == 32 || av[1][i] == 9))
			{
				if (space)
					write(1, " ", 1);
				space = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
