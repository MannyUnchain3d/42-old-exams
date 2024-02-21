/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:31:23 by Manny             #+#    #+#             */
/*   Updated: 2023/03/18 18:34:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	nb_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = nbr;
	len = nb_len(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	res[len--] = '\0';
	while (nb)
	{
		res[len] = nb % 10 + '0';
		len--;
		nb /= 10;
	}
	return (res);
}
