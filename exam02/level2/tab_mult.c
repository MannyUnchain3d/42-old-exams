/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:52:37 by Manny             #+#    #+#             */
/*   Updated: 2023/03/01 23:52:39 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb > 10)
		ft_putnbr(nb / 10);
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
}

int	main(int ac, char **av)
{
	unsigned int	nb;
	int				i;

	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		nb = ft_atoi(av[1]);
		printf("nb = %d\n", nb);
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(i * nb);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
