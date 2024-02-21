/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:03:55 by Manny             #+#    #+#             */
/*   Updated: 2023/02/01 01:18:48 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nb(int nb)
{
	char	str[10] = "0123456789";

	if (nb > 9)
		write_nb(nb / 10);
	write(1, &str[nb % 10], 1);
}

int	main(void)
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			write_nb(i);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
