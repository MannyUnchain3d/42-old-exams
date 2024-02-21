/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:02:32 by Manny             #+#    #+#             */
/*   Updated: 2023/02/03 00:09:36 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*s1 = "banana";
// 	char	*s2 = "coconut";
// 	char	*s3 = "banana";
// 	char	*s4 = "hi";

// 	printf("%i X ", ft_strcmp(s1, s2));
// 	printf("%i\n", strcmp(s1, s2));
// 	printf("%i X ", ft_strcmp(s1, s3));
// 	printf("%i\n", strcmp(s1, s3));
// 	printf("%i X ", ft_strcmp(s1, s4));
// 	printf("%i\n", strcmp(s1, s4));
// 	printf("%i X ", ft_strcmp(s4, s1));
// 	printf("%i\n", strcmp(s4, s1));
// 	return (0);
// }
