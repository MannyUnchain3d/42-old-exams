/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:04:26 by Manny             #+#    #+#             */
/*   Updated: 2023/02/03 12:52:23 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str[i])
		{
			j = 1;
			if (str[i] >= 'A' && str[i] <= 'Z')
				j = str[i] - 64;
			if (str[i] >= 'a' && str[i] <= 'z')
				j = str[i] - 96;
			while (j >= 1)
			{
				write(1, &str[i], 1);
				j--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
