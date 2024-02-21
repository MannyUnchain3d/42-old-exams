/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:04:32 by Manny             #+#    #+#             */
/*   Updated: 2023/03/17 18:40:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrev(char *str)
{
	int		i = -1;
	int		len = 0;
	char	tmp = str[i];

	while (str[len])
		len++;
	while (++i < --len)
	{
		str[i] = str[len];
		str[len] = tmp;
	}
	return (str);
}
