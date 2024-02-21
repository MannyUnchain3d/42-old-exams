/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:56:36 by Manny             #+#    #+#             */
/*   Updated: 2023/03/13 16:07:15 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char input = 0b01000001;

// 	printf("Input: ");
// 	for (int i = 7; i >= 0; i--)
// 	{
// 		printf("%d", (input >> i) & 1);
// 	}
// 	printf("\nOutput: ");
// 	for (int i = 7; i >= 0; i--)
// 	{
// 	printf("%d", (swap_bits(input) >> i) & 1);
// 	}
// 	printf("\n");
// 	return (0);
// }
