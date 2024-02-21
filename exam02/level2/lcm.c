/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:01:11 by Manny             #+#    #+#             */
/*   Updated: 2023/03/14 21:29:52 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", lcm(122, 22));
// 	printf("%d\n", lcm(100, 10));
// 	printf("%d\n", lcm(4242, 42));
// 	printf("%d\n", lcm(5, 9));
// 	return (0);
// }
