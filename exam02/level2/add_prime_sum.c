/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:35:47 by Manny             #+#    #+#             */
/*   Updated: 2023/03/14 20:13:06 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while ((nb / 2) >= i)
	{
		if (!(nb % i))
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	nb;
	int	sum;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		sum = 0;
		while (nb > 0)
		{	
			//printf("nb: %d sum: %d\n", nb, sum);
			if (is_prime(nb--))
			{	
				//printf("nb--: %d sum: %d\n", nb, sum);
				sum += (nb + 1);
				//printf("sum: %d\n", sum);

			}
		}
		ft_putnbr(sum);
	}
	if (ac != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
