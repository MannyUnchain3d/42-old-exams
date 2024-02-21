/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:51:00 by Manny             #+#    #+#             */
/*   Updated: 2023/03/18 21:40:23 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*arr;
	int	len;
	int	i;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (start != end)
	{
		arr[i++] = start;
		start += (start < end) ? 1 : -1;
	}
	arr[i] = start;
	return (arr);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	int	arr_len;
// 	int	*arr;

// 	arr_len = abs(atoi(av[2]) - atoi(av[1]));
// 	arr = ft_range(atoi(av[1]), atoi(av[2]));
// 	for (int i = 0; i <= arr_len; i++)
// 		printf("%d ", arr[i]);
// 	free(arr);
// 	return (EXIT_SUCCESS);
// }
