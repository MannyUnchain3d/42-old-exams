/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:11:25 by Manny             #+#    #+#             */
/*   Updated: 2023/03/01 23:26:19 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int	max;

	if (len > 0)
	{
		max = tab[--len];
		while (len--)
		{
			if (max < tab[len])
				max = tab[len];
		}
		return (max);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int tab[3] = {3, 224, 42};
// 	printf("max: %d", max(tab, 3));
// 	return (0);
// }
