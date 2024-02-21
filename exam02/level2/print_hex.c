/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:39:22 by Manny             #+#    #+#             */
/*   Updated: 2023/03/01 23:00:23 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	print_hex(int nb)
{
	char	hex[] = "0123456789abcdef";

	if (nb >= 16)
		print_hex(nb / 16);
	write(1, &hex[nb % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
