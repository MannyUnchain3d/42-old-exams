/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:22:41 by Manny             #+#    #+#             */
/*   Updated: 2023/03/18 16:36:53 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	start;
	int	end;
	int	flag;
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0)
		{
			while (av[1][i] == '\0' || av[1][i] == 32 || av[1][i] == 9)
				i--;
			end = i;
			while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
				i--;
			start = i + 1;
			flag = start;
			while (start <= end)
			{
				write (1, &av[1][start], 1);
				start++;
			}
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
