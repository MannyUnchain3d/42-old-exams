/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:22:00 by Manny             #+#    #+#             */
/*   Updated: 2023/02/28 15:22:02 by Manny            ###   ########.fr       */
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
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				space = 1;
			if (!(av[1][i] == ' ' || av[1][i] == '\t'))
			{
				if (space)
					write (1, "   ", 3);
				space = 0;
				write (1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
