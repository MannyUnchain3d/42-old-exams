/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:14 by Manny             #+#    #+#             */
/*   Updated: 2023/02/01 16:35:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_chars(char *s1, char *s2)
{
	int tab[256] = {0};
	int	i;

	i = 0;
	while (s2[i])
		tab[(int)s2[i++]] = 1;
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			tab[(int)s1[i]] = 2;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		print_chars(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
