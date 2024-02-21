/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:15:54 by Manny             #+#    #+#             */
/*   Updated: 2023/03/14 20:53:53 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	nb1;
	int	nb2;

	if (ac == 3)
	{
		nb1 = atoi(av[1]);
		nb2 = atoi(av[2]);
		if (nb1 > 0 && nb2 > 0)
		{
			while (nb1 != nb2)
			{
				if (nb1 > nb2)
				{	
					nb1 -= nb2;
					//printf("if loop: %d\n", nbr1);
				}
				else
				{
					nb2 -= nb1;
					//printf("else loop: %d\n", nbr2);
				}
			}
			printf("%d", nb1);
		}
	}
	printf("\n");
	return (0);
}
