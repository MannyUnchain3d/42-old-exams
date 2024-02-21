/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:49:29 by Manny             #+#    #+#             */
/*   Updated: 2023/04/20 00:38:05 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
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
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("ft_atoi vs atoi\n");
// 	printf("     %d --", ft_atoi("   +42"));
// 	printf(" %d\n", atoi("   +42"));
// 	printf("    %d --", ft_atoi("   -42"));
// 	printf(" %d\n", atoi("   -42"));
// 	printf("      %d --", ft_atoi(" --42"));
// 	printf(" %d\n", atoi("   --42"));
// 	printf("      %d --", ft_atoi(" ++42"));
// 	printf(" %d\n", atoi("   ++42"));
// 	printf("      %d --", ft_atoi(" +-42"));
// 	printf(" %d\n", atoi("   +-42"));
// 	return (0);
// }
