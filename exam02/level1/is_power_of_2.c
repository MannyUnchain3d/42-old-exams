/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:36:16 by Manny             #+#    #+#             */
/*   Updated: 2023/01/31 21:11:29 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", is_power_of_2(1024));
// 	printf("%d\n", is_power_of_2(1023));
// 	printf("%d\n", is_power_of_2(0));
// 	printf("%d\n", is_power_of_2(1));
// }