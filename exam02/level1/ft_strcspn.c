/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:06:31 by Manny             #+#    #+#             */
/*   Updated: 2023/03/14 13:59:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("\nft_strcspn: %lu\n", ft_strcspn("test", "s"));
// 	printf("strcspn:    %lu\n\n", strcspn("test", "s"));
// 	printf("ft_strcspn: %lu\n", ft_strcspn("test", "f"));
// 	printf("strcspn:    %lu\n", strcspn("test", "f"));
// }
