/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:51:17 by Manny             #+#    #+#             */
/*   Updated: 2023/03/18 16:57:27 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int	i = 0;
	int	start;
	int	end;
	int	flag;

	if (ac > 1 && av[1][i])
	{
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		start = i;
		while (av[1][i] != '\0' && av[1][i] != 32 && av[1][i] != 9)
			i++;
		end = i;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while (av[1][i])
		{
			while ((av[1][i] == 32 && av[1][i + 1] == 32) || (av[1][i] == 9 && av[1][i + 1] == 9))
				i++; 
			if (av[1][i] == 32 || av[1][i] == 9)
				flag = 1;
			write(1, &av[1][i], 1);
			i++;
		}
		if (flag)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
