/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:27:23 by Manny             #+#    #+#             */
/*   Updated: 2023/02/24 19:56:10 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	is_valid(char c, int base)
{
	char	digits[17] = "0123456789abcdef";
	char	digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int sign;

	res = 0;
	while (is_blank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (is_valid(*str, str_base))
		res = res * str_base + value_of(*str++);
	return (res * sign);
}
