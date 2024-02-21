/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:42:37 by Manny             #+#    #+#             */
/*   Updated: 2023/03/20 15:35:54 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	if (c == 32 || c == 9 || c == 10)
		return (1);
	return (0);
}

char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	*word;
	char	**ret;

	ret = malloc(sizeof(char *) * 5000);
	while (str[i])
	{
		while (is_space(str[i]) == 1)
			i++;
		if (!str[i])
			break ;
		word = malloc(sizeof(char) * 5000);
		while (is_space(str[i]) == 0)
			word[j++] = str[i++];
		word[j] = '\0';
		j = 0;
		ret[k] = word;
		k++;
	}
	ret[k] = NULL;
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "les chaussettes de l'archiduchesse sont-elles seches archiseches";
// 	char	**words = ft_split(str);
// 	int	i = 0;

// 	if (words == NULL)
// 	{
// 		printf("Error: failed to allocate memory\n");
// 		return (1);
// 	}
// 	while (words[i] != NULL)
// 	{
// 		printf("[%s] ", words[i]);
// 		free(words[i]);
// 		i++;
// 	}
// 	free(words);
// 	return (0);
// }
