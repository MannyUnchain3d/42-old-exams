/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:35:26 by Manny             #+#    #+#             */
/*   Updated: 2023/02/18 23:31:06 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

// #include <stdio.h>

// int	main()
// {
// 	int arr[] = { 3, 7, 1, 9, 2, 5 };
// 	unsigned int	size = sizeof(arr) / sizeof(arr[0]);

// 	printf("Before sorting: ");
// 	for (unsigned int i = 0; i < size; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	sort_int_tab(arr, size);
// 	printf("After sorting: ");
// 	for (unsigned int i = 0; i < size; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
