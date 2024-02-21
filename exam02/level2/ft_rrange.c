/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:06:30 by Manny             #+#    #+#             */
/*   Updated: 2023/03/18 21:40:05 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*arr;
	int	i;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (end != start)
	{
		arr[i++] = end;
		end -= (end > start) ? 1 : -1;
	}
	arr[i] = end;
	return (arr);
}


// #include <stdio.h>

// int	main(void)
// {
// 	int	start;
// 	int	end;
// 	int	*result;

// 	start = 3;
// 	end = 0;
// 	result = ft_rrange(start, end);
// 	if (result == NULL)
// 	{
// 		printf("Error: failed to allocate memory\n");
// 		return (1);
// 	}
// 	if (start < end)
// 		for (int i = 0; i <= end - start; i++)
// 			printf("%d\n", result[i]);
// 	else
// 		for (int i = 0; i <= start - end; i++)
// 			printf("%d\n", result[i]);
// 	free(result);
// 	return (0);
// }
