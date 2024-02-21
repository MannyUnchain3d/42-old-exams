/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:01:13 by Manny             #+#    #+#             */
/*   Updated: 2023/04/21 17:39:09 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb > 9)
		ft_putnbr(nb / 10);
	digit = (nb % 10) + '0';
	write(1, &digit, 1);
}

int	main(int ac, char **av)
{
	(void)av;

	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}
